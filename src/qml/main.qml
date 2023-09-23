import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts
import QtLocation
import QtPositioning
import Esri.ArcGISRuntime
import ProcessFactory 1.0

ApplicationWindow {
    id: window
    width: Screen.width
    height: Screen.height
    visible: false
    title: "Agrorama"

    LoadingScreen{
        id: loadingScreen
    }

    SystemPalette {
        id: systemPalette;
        colorGroup: SystemPalette.Active
    }

    ColumnLayout{
        anchors.fill: parent
        id: mainScreen
        spacing: 0

        MenuBar {
            id: menuBar
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop

            Menu {
                title: qsTr("&Project")
                Action { text: qsTr("&New...")
                    onTriggered:MenuActions.newProject(leftWindow);
                }
                Action { text: qsTr("&Open...")
                    onTriggered: {
                        MenuActions.openProject(leftWindow);
                        useCuda.checked = YamlSettings.getUse_cuda();
                    }
                }
                MenuSeparator { }
                Action { text: qsTr("&Quit")
                    onTriggered: window.close()
                }
            }

            Menu {
                title: qsTr("&Configure")
                Action { text: qsTr("&Settings")
                    onTriggered: MenuActions.setSettings()
                }
            }

            Menu{
                title: qsTr("&Options")
                MenuItem {
                    id: useCuda
                    text: "Use Cuda"
                    checked: true
                    checkable: true
                    onCheckedChanged: YamlSettings.setUse_cuda(useCuda.checked);
                }
            }

            Menu {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }

        RowLayout{
            id: row
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing:0


            ColumnLayout {
                id: leftWindow
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width * 0.1
                spacing: 0
                enabled: false

                Rectangle{
                    id: editModeBox
                    Layout.preferredHeight: 0.3 * parent.height
                    Layout.fillWidth: true
                    color: "transparent"

                    ColumnLayout{
                        anchors.fill: parent
                        spacing: 0

                        Rectangle{
                            id: title_1
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.05 * leftWindow.height
                            color: "transparent"
                            Rectangle{
                                width: parent.width
                                height: 0.04 * leftWindow.height
                                anchors.centerIn: parent
                                color: "#1E1C0B"
                                Text {
                                    anchors.fill: parent
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    font.family: "Inter"
                                    color: "white"
                                    font.pointSize: 15
                                    text: qsTr("Select Waypoints")
                                }
                            }
                        }

                        Button {
                            id: kml
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.06 * leftWindow.height
                            text: qsTr("Load KML")
                            font.pointSize: 13
                            enabled: true
                            onClicked: {
                                loader.loadKml();
                            }
                        }

                        SwitchDelegate {
                            id: editMode
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.35 * parent.height
                            text: qsTr("Edit Mode")
                            contentItem: Text {
                                rightPadding: editMode.indicator.width + editMode.spacing
                                text: editMode.text
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                font.pointSize: 14
                                color: systemPalette.text
                                opacity: enabled ? 1.0 : 0.3
                                elide: Text.ElideRight
                            }
                            indicator: Rectangle {
                                implicitWidth: 48
                                implicitHeight: 26
                                x: editMode.width - width - editMode.rightPadding
                                y: editMode.height / 2 - height / 2
                                radius: 13
                                color: editMode.checked ? "#17a81a" : "transparent"
                                border.color: editMode.checked ? "#17a81a" : "#cccccc"

                                Rectangle {
                                    x: editMode.checked ? parent.width - width : 0
                                    width: 26
                                    height: 26
                                    radius: 13
                                    color: editMode.down ? "#cccccc" : "#ffffff"
                                    border.color: editMode.checked ? (editMode.down ? "#17a81a" : "#21be2b") : "#999999"
                                }
                            }
                            Rectangle{
                                id: editBackground
                                anchors.fill: parent
                                color: "transparent"
                            }
                            onCheckedChanged: {
                                if(!checked){
                                    map.enableDragDrop();
                                    slider.visible = false;
                                    generate.enabled = false;
                                    orthomap.enabled = false;
                                    grid.deactivate();
                                    editBackground.color = "transparent"
                                }
                                else if (checked){
                                    map.disableDragDrop();
                                    slider.visible = true;
                                    generate.enabled = true;
                                    grid.activate();
                                    editBackground.color = "green"
                                    editBackground.opacity = 0.1
                                }
                            }
                        }

                        TextEdit {
                            readOnly: true
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.2 * parent.height
                            id: meters
                            verticalAlignment: Text.AlignVCenter
                            horizontalAlignment: Text.AlignHCenter
                            color: systemPalette.text
                            font.pointSize: 14
                        }
                    }
                }

                Rectangle{
                    Layout.preferredHeight: 0.05 * parent.height
                    Layout.fillWidth: true
                    color: "transparent"
                    id: separator_1
                }

                Rectangle{
                    id: generateBox
                    Layout.preferredHeight: 0.2 * leftWindow.height
                    Layout.fillWidth: true
                    color: "transparent"
                    ColumnLayout{
                        anchors.fill: parent
                        spacing: 0

                        Rectangle{
                            id: title_2
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.05 * leftWindow.height
                            color: "transparent"
                            Rectangle{
                                width: parent.width
                                height: 0.04 * leftWindow.height
                                anchors.centerIn: parent
                                color: "#1E1C0B"
                                Text {
                                    anchors.fill: parent
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    color: "white"
                                    font.pointSize: 15
                                    font.family: "Inter"
                                    text: qsTr("Process Data")
                                }
                            }
                        }

                        Button{
                            id: generate
                            text: qsTr("Generate")
                            font.pointSize: 14
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.06 * leftWindow.height
                            enabled: false
                            onClicked: {
                                orthomap.enabled = true;
                                TilesHandler.generateCsv();
                                let path = YamlSettings.pathJoin([YamlSettings.getProject_path(), YamlSettings.getYamlParamsName()]);
                                YamlSettings.dumpToYaml(path);
                                path = YamlSettings.pathJoin([YamlSettings.getProject_path(), YamlSettings.getGuiSubDir(), YamlSettings.getYamlSaveName()]);
                                YamlSettings.dumpToYaml(path);
                            }
                        }

                        Button{
                            id: orthomap
                            text: qsTr("Orthomap")
                            font.pointSize: 14
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.06 * leftWindow.height
                            enabled: false

                            onClicked:{
                                procfactory.spawnProcess("../testing/test");
                                loadingScreen.visible = true;
                            }
                        }

                        ProcessFactory{
                            id: procfactory
                            onProcessTerminated: (exitCode, success) => {
                                loadingScreen.visible = false;
                                if (success) {
                                    console.log("Process terminated successfully with exit code " + exitCode);
                                    loader.loadTif()
                                }
                                else {
                                    console.error("Process terminated with error: " + exitCode);             
                                    // TODO: Rendere piu palese che qualcosa è andato storto (magari un equivalente dell'alert js?)
                                }
                            }
                        }
                    }
                }

                Rectangle{
                    Layout.preferredHeight: 0.05 * parent.height
                    Layout.fillWidth: true
                    color: "transparent"
                    id: separator_2
                }

                Rectangle{
                    id: tifBox
                    Layout.preferredHeight: 0.25 * leftWindow.height
                    Layout.fillWidth: true
                    color: "transparent"
                    ColumnLayout{
                        anchors.fill: parent
                        spacing: 0

                        Rectangle{
                            id: title_3
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.05 * leftWindow.height
                            color: "transparent"
                            Rectangle{
                                width: parent.width
                                height: 0.04 * leftWindow.height
                                anchors.centerIn: parent
                                color: "#1E1C0B"
                                Text {
                                    anchors.fill: parent
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignHCenter
                                    font.family: "Inter"
                                    color: "white"
                                    font.pointSize: 15
                                    text: qsTr("Visualize Result")
                                }
                            }
                        }

                        Button {
                            id: tif
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.06 * leftWindow.height
                            text: qsTr("Load TIF")
                            font.pointSize: 13
                            enabled: true
                            onClicked: {
                                loader.loadTif();
                            }
                        }

                        Button {
                            id: colorTif
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.06 * leftWindow.height
                            text: qsTr("Color Raster")
                            font.pointSize: 13
                            enabled: true
                            onClicked: {
                                map.applyRasterFunction();
                            }
                        }

                        TextEdit {
                            id: opacity
                            readOnly: true
                            visible: true
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.1 * parent.height
                            verticalAlignment: Text.AlignBottom
                            horizontalAlignment: Text.AlignHCenter
                            color: systemPalette.text
                            font.pointSize: 10
                            text: qsTr("Layer Opacity")
                        }

                        Rectangle{
                            id: opacitySliderBox
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.15 * parent.height
                            color: "transparent"
                            Slider{
                                id: opacitySlider
                                visible: true
                                orientation: Qt.Horizontal
                                width: parent.width * 0.85
                                anchors.centerIn: parent
                                from: 0
                                to: 1
                                value: map.getOpacity()
                                onMoved: {
                                    map.setOpacity(value);
                                }

                                handle: Rectangle {
                                    x: opacitySlider.leftPadding + opacitySlider.visualPosition * (opacitySlider.availableWidth - width)
                                    y: opacitySlider.topPadding + opacitySlider.availableHeight / 2 - height / 2
                                    implicitWidth: 20
                                    implicitHeight: 20
                                    radius: 10
                                    color: opacitySlider.pressed ? "#f0f0f0" : "#f6f6f6"
                                    border.color: "#bdbebf"
                                }
                            }
                        }


                    }
                }
            }

            MapForm{
                id: map
                Layout.preferredWidth: parent.width*0.9
                Layout.fillHeight: true

                onActiveFocusChanged: MapForm.forceActiveFocus();

                MapGrid{
                    id: grid
                    anchors.fill: parent
                }

                RasterLoader{
                    id: loader
                    onRasterFileChosen: url => {
                        map.createAndAddRasterLayer(url);
                    }
                    onKmlFileChosen: url => {
                        console.log(url)
                        map.createAndAddKmlLayer(url);
                    }
                }

                Slider {
                    id: slider
                    visible: false
                    height: parent.height*0.9
                    width: parent.width*0.03
                    orientation: Qt.Vertical
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    from: 20
                    to: 300
                    value: grid.getWidth()
                    onMoved: {
                        grid.setWidth(value);
                    }

                    handle: Rectangle {
                        y: slider.bottomPadding + slider.visualPosition * (slider.availableHeight - height)
                        x: slider.leftPadding + slider.availableWidth / 2 - width / 2
                        implicitWidth: 30
                        implicitHeight: 30
                        radius: 15
                        color: slider.pressed ? "#f0f0f0" : "#f6f6f6"
                        border.color: "#bdbebf"
                    }
                }
            }
        }
    }
}
