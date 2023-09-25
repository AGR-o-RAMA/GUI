import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls
import Esri.ArcGISRuntime
import Esri.ArcGISExtras

Item {
    id: loader
    anchors.fill: parent
    signal rasterFileChosen(url url);
    signal kmlFileChosen(url url);
    property var supportedRasterExtensions: ["geotiff","tif","tiff","jpg","jpeg","png","ovr"]
    property var supportedKmlExtensions: ["kml"]

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: {
            loader.rasterFileChosen(fileDialog.selectedFile)
        }
        onRejected: {
            console.error("Raster Loading Canceled")
        }
        Component.onCompleted: visible = false
    }

    FileDialog {
        id: kmlFileDialog
        title: "Please choose a file"
        onAccepted: {
            loader.kmlFileChosen(kmlFileDialog.selectedFile)
        }
        onRejected: {
            console.error("Raster Loading Canceled")
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

            if (!loader.validateFileExtension(drop.urls[0], supportedRasterExtensions))
                return;

            if (drop.proposedAction !== Qt.MoveAction && drop.proposedAction !== Qt.CopyAction)
                return;

            drop.acceptProposedAction();
            loader.rasterFileChosen(drop.urls[0]);
        }
    }

    function validateFileExtension(filePath,supportedExtensions) {
        var path = filePath.toString();
        path = path.replace(/^(file:\/{2})/,"");
        const extension = path.split('.').pop();
        const idx = supportedExtensions.indexOf(extension);
        return idx !== -1;
    }

    function setSupportedExtensions(dialog, supportedExtensions){
        let nameFiltersString = "";
        for (let i = 0; i < supportedExtensions.length; i++)
            nameFiltersString += "*." + supportedExtensions[i] + " ";
        dialog.nameFilters = nameFiltersString;
    }

    function loadTif(path) {
        setSupportedExtensions(fileDialog, supportedRasterExtensions);
        fileDialog.currentFolder = "file://" + path;
        fileDialog.open();
    }

    function loadKml(path) {
        setSupportedExtensions(kmlFileDialog, supportedKmlExtensions);
        fileDialog.currentFolder = "file://" + path;
        kmlFileDialog.open();
    }
}
