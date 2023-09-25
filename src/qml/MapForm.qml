import QtQuick
import QtQuick.Controls
import Esri.ArcGISRuntime
import Esri.ArcGISExtras
import QtQuick.Dialogs


Item {
    id: root

    MapView {
        id: mapView
        objectName: "mapView"
        anchors.fill: parent

        Component.onCompleted: {
            forceActiveFocus();
        }

        Map {
            id: map
            initialViewpoint: viewpoint;

            Basemap {
                initStyle: Enums.BasemapStyleArcGISCommunity
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


    property RasterLayer rasterLayer: null
    property Raster raster: null
    property RasterLayer tempRasterLayer: null
    property Raster tempRaster: null
    property KmlLayer kmlLayer: null

    function zoomToRaster(){
        mapView.setViewpointCenterAndScale(rasterLayer.fullExtent.center, 80000);
    }

    function zoomToKml(){
        mapView.setViewpointCenterAndScale(kmlLayer.fullExtent.center, 8000);
    }

    function getOpacity(){
        if (!rasterLayer) return 1
        return rasterLayer.opacity;
    }

    function setOpacity(value){
        if (!rasterLayer) return
        rasterLayer.opacity = value;
    }

    function createAndAddRasterLayer(rasterUrl) {
        const index = map.operationalLayers.indexOf(rasterLayer);
        raster = ArcGISRuntimeEnvironment.createObject("Raster", {path: rasterUrl});
        raster.path = rasterUrl;
        rasterLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: raster});
        map.operationalLayers.remove(index);
        map.operationalLayers.append(rasterLayer);
        rasterLayer.onLoadStatusChanged.connect(zoomToRaster);
    }

    function createAndAddKmlLayer(kmlUrl) {
        const index = map.operationalLayers.indexOf(kmlLayer);
        const kmlDataset = ArcGISRuntimeEnvironment.createObject("KmlDataset", {url: kmlUrl});
        kmlLayer = ArcGISRuntimeEnvironment.createObject("KmlLayer", {dataset: kmlDataset});
        map.operationalLayers.remove(index);
        map.operationalLayers.append(kmlLayer);
        kmlLayer.onLoadStatusChanged.connect(zoomToKml);
    }

    function applyRasterFunction() {
        // create the raster function
        const rasterFunction = ArcGISRuntimeEnvironment.createObject("RasterFunction", {path: "file://"+CurDirPath+"/color.json"});
        rasterFunction.arguments.setRaster("raster", raster);
        rasterFunction.arguments.setRaster("raster", raster); //don't know why the raster has to be added twice, but once doesn't work

        // create the raster from the raster function
        tempRasterLayer = rasterLayer; tempRaster = raster;
        const index = map.operationalLayers.indexOf(rasterLayer);
        raster = ArcGISRuntimeEnvironment.createObject("Raster", {rasterFunction: rasterFunction});
        rasterLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: raster});

        //add the layer (removing the underlying raster)
        map.operationalLayers.remove(index);
        map.operationalLayers.append(rasterLayer);
    }

    function removeRasterFunction(){
        const index = map.operationalLayers.indexOf(rasterLayer);
        rasterLayer = tempRasterLayer; raster = tempRaster;
        map.operationalLayers.remove(index);
        map.operationalLayers.append(rasterLayer);
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
