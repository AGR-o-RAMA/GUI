import QtQuick
import QtQuick.Controls
import Esri.ArcGISRuntime
import Esri.ArcGISExtras
import QtQuick.Dialogs


Item {
    id: root
    property var rasterLayer: null

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

            Basemap {
                initStyle: Enums.BasemapStyleArcGISCommunity
            }

            RasterLayer {
                Raster {
                    path: "home/flavio/Downloads/example/example.tif"
                }

                onLoadStatusChanged: {
                    if (loadStatus !== Enums.LoadStatusLoaded)
                        return;

                    mapView.setViewpointCenterAndScale(fullExtent.center, 800);
                }
            }
        }

        function generateCoordinates(point){
            res = mapView.screenToLocation(point);
        }
    }


    Item {
        id: loader
        anchors.fill: parent
        signal rasterFileChosen(url url);
        property var supportedExtensions: ["img","I12","dt0","dt1","dt2","tc2","geotiff","tif", "tiff", "hr1","jpg","jpeg","jp2","ntf","png","i21","ovr"]
        property var rasterLayer: null

        onRasterFileChosen: url => {
            createAndAddRasterLayer(url);
        }

        FileDialog {
            id: fileDialog
            title: "Please choose a file"
            onAccepted: {
                console.log("LOADING")
                loader.rasterFileChosen(fileDialog.selectedFile)
            }
            onRejected: {
                console.log("Canceled")
            }
            Component.onCompleted: visible = false
        }

        DropArea {
            anchors.fill: parent

            onDropped: (drop) => {
                if (!drop.hasText)
                    return;

                if (drop.urls.length !== 1)
                    return;

                if (!loader.validateFileExtension(drop.urls[0]))
                    return;

                if (drop.proposedAction !== Qt.MoveAction && drop.proposedAction !== Qt.CopyAction)
                    return;

                drop.acceptProposedAction();
                loader.rasterFileChosen(drop.urls[0]);
            }
        }

        function validateFileExtension(filePath) {
            var path = filePath.toString();
            path = path.replace(/^(file:\/{2})/,"");
            console.log(path);
            const extension = path.split('.').pop();
            const idx = supportedExtensions.indexOf(extension);
            return idx !== -1;
        }

        onSupportedExtensionsChanged: {
            let nameFiltersString = "Raster files (";
            for (let i = 0; i < supportedExtensions.length; i++)
                nameFiltersString += "*." + supportedExtensions[i] + " ";

            nameFiltersString += ")";
            fileDialog.nameFilters = nameFiltersString;
        }
    }

    function createAndAddRasterLayer(rasterUrl) {
       const newRaster = ArcGISRuntimeEnvironment.createObject("Raster", {path: rasterUrl});
       rasterLayer = ArcGISRuntimeEnvironment.createObject("RasterLayer", {raster: newRaster});

       rasterLayer.loadStatusChanged.connect(zoomToRaster);

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

    function loadTif() {
        fileDialog.open();
    }

    function disableDragDrop(){
        mapView.focus = false
    }

    function enableDragDrop(){
        mapView.focus = true
    }
}
