import QtQuick
import QtQuick.Controls
import Esri.ArcGISRuntime
import Esri.ArcGISExtras
import QtQuick.Dialogs


Item {
    property var rasterLayer: null
    readonly property url dataPath: (System.writableLocationUrl(System.StandardPathsHomeLocation) + "/Downloads")
    MapView {
        id: mapView
        objectName: "mapView"
        anchors.fill: parent

        Component.onCompleted: {
            // Set the focus on MapView to initially enable keyboard navigation
            forceActiveFocus();
        }

        Map {
            id: map
            initialViewpoint: viewpoint;

            Basemap {
                initStyle: Enums.BasemapStyleArcGISCommunity
            }

            RasterLayer {
                opacity: 0.5
                Raster {
                    id: theRaster
                    path: ""
                }

                onLoadStatusChanged: {
                    if (loadStatus !== Enums.LoadStatusLoaded)
                        return;

                    mapView.setViewpointCenterAndScale(fullExtent.center, 800);
                }
            }

            ViewpointCenter {
                id: viewpoint

                center: Point {
                    x: 12.5035803441948 // long
                    y: 41.89117217327389 // lat
                    spatialReference: SpatialReference { wkid: 4326 } // USE THIS WKID FOR LAT-LONG
                }

                targetScale: 1000
            }
        }


        function generateCoordinates(point){
            const c = mapView.screenToLocation(point.x, point.y);
            const projected = GeometryEngine.project(c, Factory.SpatialReference.createWgs84());
            return Qt.point(projected.x, projected.y);
        }
    }

    function createAndAddRasterLayer(rasterUrl) {
       const newRaster = ArcGISRuntimeEnvironment.createObject("Raster", {path: rasterUrl});
       rasterLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: newRaster});
       rasterLayer.loadStatusChanged.connect(zoomToRaster);

       theRaster.path = rasterUrl

       map.operationalLayers.clear();
       map.operationalLayers.append(rasterLayer);
    }

    function zoomToRaster(){
        if (rasterLayer === null)
            return;

        if (rasterLayer.loadStatus !== Enums.LoadStatusLoaded)
            return;

        mapView.setViewpointCenterAndScale(rasterLayer.fullExtent.center, 800);
    }

    function applyRasterFunction() {
        // create raster function
        const rasterFunction = createRasterFunction();

        // check for valid raster function
        if (!rasterFunction)
            return;

        // create the raster from the raster function
        const newRaster = ArcGISRuntimeEnvironment.createObject("Raster", {rasterFunction: rasterFunction});
        rasterLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: newRaster});
        rasterLayer.opacity = 0.5;

        // add raster to map
        map.operationalLayers.append(rasterLayer);
    }

    function createRasterFunction() {
        // create the raster function
        const rasterFunction = ArcGISRuntimeEnvironment.createObject("RasterFunction", {path: dataPath + "/color.json"});

        // check for valid raster function
        if (!rasterFunction){
            return;
        }

        rasterFunction.arguments.setRaster("raster", theRaster);
        rasterFunction.arguments.setRaster("raster", theRaster);
        return rasterFunction;
    }
    function disableDragDrop(){
        mapView.focus = false;
        mapView.interactionEnabled = false;
    }

    function enableDragDrop(){
        mapView.focus = true;
        mapView.interactionEnabled = true;
    }
}
