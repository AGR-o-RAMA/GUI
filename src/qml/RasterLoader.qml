import QtQuick
import QtQuick.Dialogs

Item {
    id: loader
    anchors.fill: parent
    signal rasterFileChosen(url url);
    property var supportedExtensions: ["img","I12","dt0","dt1","dt2","tc2","geotiff","tif", "tiff", "hr1","jpg","jpeg","jp2","ntf","png","i21","ovr"]
    property var rasterLayer: null

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

    function loadTif() {
        fileDialog.open();
    }
}
