import QtQuick
import QtQuick.Controls
import Esri.ArcGISRuntime
import Esri.ArcGISExtras
import QtQuick.Dialogs


Item {

    property var currentLayer: null
    property var currentRaster: null

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

    function addLayer(clear){
        if (clear)
            map.operationalLayers.clear();
        map.operationalLayers.append(currentLayer);
        currentLayer.loadStatusChanged.connect(zoomToLayer);
    }

    function zoomToLayer(){
        if (currentLayer == null)
            return;

        if (currentLayer.loadStatus !== Enums.LoadStatusLoaded)
            return;

        mapView.setViewpointCenterAndScale(currentLayer.fullExtent.center, 80000);
    }

    function getOpacity(){
        if (!currentLayer) return 1
        return currentLayer.opacity;
    }

    function setOpacity(value){
        if (!currentLayer) return
        currentLayer.opacity = value;
    }

    function createAndAddRasterLayer(rasterUrl) {
       currentRaster = ArcGISRuntimeEnvironment.createObject("Raster", {path: rasterUrl});
       currentRaster.path = rasterUrl
       currentLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: currentRaster});
       addLayer(true);
    }

    function createAndAddKmlLayer(kmlUrl) {
        // create the dataset from a local file
        const kmlDataset = ArcGISRuntimeEnvironment.createObject("KmlDataset", {url: kmlUrl});
        // create the layer
        currentLayer = ArcGISRuntimeEnvironment.createObject("KmlLayer", {dataset: kmlDataset});
        addLayer(true);
    }

    function applyRasterFunction() {
        // create the raster function
        const rasterFunction = ArcGISRuntimeEnvironment.createObject("RasterFunction", {path: "file:///home/flavio/Code/agrorama/examples/color.json"});
        rasterFunction.arguments.setRaster("raster", currentRaster);
        rasterFunction.arguments.setRaster("raster", currentRaster); //don't know why the raster has to be added twice, but once doesn't work

        // create the raster from the raster function
        currentRaster = ArcGISRuntimeEnvironment.createObject("Raster", {rasterFunction: rasterFunction});
        currentLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: currentRaster});
        addLayer(true);
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
