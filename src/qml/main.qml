import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Layouts
import QtLocation
import QtPositioning

import Esri.ArcGISRuntime

ApplicationWindow {
    id: window
    width: Screen.width
    height: Screen.height
    visible: true
    title: "Agrorama"

    ColumnLayout{
        anchors.fill: parent
        id: mainScreen
        spacing: 0

        MenuBar {
            id: menuBar
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignTop

            Menu {
                title: qsTr("&File")
                Action { text: qsTr("&New...")
                    onTriggered: print("OK")
                }
                Action { text: qsTr("&Open...")
                    onTriggered: MenuActions.openProject()}
                Action { text: qsTr("&Save")
                    onTriggered: MenuActions.saveProject()}
                MenuSeparator { }
                Action { text: qsTr("&Quit")
                    onTriggered: window.close()
                }
            }
            Menu {
                title: qsTr("&Edit")
                Action { text: qsTr("&Cut") }
                Action { text: qsTr("&Copy") }
                Action { text: qsTr("&Paste") }
            }
            Menu {
                title: qsTr("&Configure")
                Action { text: qsTr("&Photo Path")
                    onTriggered: MenuActions.setPhotopath()
                }
                Action { text: qsTr("&Project Path")
                    onTriggered: MenuActions.setProjectPath()
                }
                Action { text: qsTr("&Output Path")
                    onTriggered: MenuActions.setOutputPath()
                }
            }

            Menu{
                title: qsTr("&Options")
                MenuItem {
                    id: useCuda
                    text: "Use Cuda"
                    checkable: true
                    onCheckedChanged: {}
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
                Layout.fillHeight: true
                Layout.preferredWidth: parent.width*0.1
                spacing: 0

                ColumnLayout{
                    id: editModeBox
                    Layout.preferredHeight: 0.3 * parent.height
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    spacing: 0

                    CheckDelegate {
                        id: editMode
                        text: qsTr("Edit Mode")
                        font.pointSize: 13
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        indicator: Rectangle {
                            implicitWidth: 26
                            implicitHeight: 26
                            x: editMode.width - width - editMode.rightPadding
                            y: editMode.topPadding + editMode.availableHeight / 2 - height / 2
                            radius: 3
                            color: "transparent"
                            border.color: editMode.down ? "#17a81a" : "#21be2b"

                            Rectangle {
                                width: 14
                                height: 14
                                x: 6
                                y: 6
                                radius: 2
                                color: editMode.down ? "#17a81a" : "#21be2b"
                                visible: editMode.checked
                            }
                        }
                        onCheckedChanged: {
                            if(checkState == Qt.Unchecked){
                                map.enableDragDrop();
                                slider.visible = false;
                                generate.enabled = false;
                                grid.deactivate();
                            }
                            else if (checkState == Qt.Checked){
                                map.disableDragDrop();
                                slider.visible = true;
                                generate.enabled = true;
                                grid.activate();
                            }
                        }
                    }

                    TextEdit {
                        id: meters
                        readOnly: true
                        visible: true
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "white"
                        font.pointSize: 15
                        text: qsTr("Tiles size \n ")
                    }
                }

                Frame{
                    Layout.preferredHeight: 0.1 * parent.height
                    Layout.fillWidth: true
                    id: separator_1
                    Rectangle{
                        height: 2
                        width: parent.width
                        anchors.verticalCenter: parent.verticalCenter
                        color: "grey"
                    }
                }

                Button{
                    id: generate
                    text: qsTr("Generate \n Orthomap")
                    font.pointSize: 17
                    Layout.fillWidth: true
                    Layout.preferredHeight: 0.1 * parent.height
                    Layout.fillHeight: true
                    enabled: false
                    onClicked: {
                        TilesHandler.generateCsv();
                    }
                }

                Frame{
                    Layout.preferredHeight: 0.1 * parent.height
                    Layout.fillWidth: true
                    id: separator_2
                    Rectangle{
                        height: 2
                        width: parent.width
                        anchors.verticalCenter: parent.verticalCenter
                        color: "grey"
                    }
                }

                Rectangle{
                    id: layersBox
                    Layout.preferredHeight: 0.5 * parent.height
                    Layout.fillWidth: true
                    color: "transparent"
                    ColumnLayout{
                        anchors.fill: parent
                        spacing: 0

                        Frame{
                            Layout.fillWidth: true
                            Layout.preferredHeight: 0.1 * parent.height
                            Slider{
                                id: opacitySlider
                                visible: true
                                orientation: Qt.Horizontal
                                anchors.verticalCenter: parent.verticalCenter
                                from: 0
                                to: 1
                                value: map.getOpacity()
                                onMoved: {
                                    map.setOpacity(value);
                                }
                            }
                        }

                        Button {
                            id: tif
                            Layout.fillWidth: true
                            Layout.fillHeight: true
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
                            Layout.fillHeight: true
                            text: qsTr("Color Raster")
                            font.pointSize: 13
                            enabled: true
                            onClicked: {
                                map.applyRasterFunction();
                            }
                        }

                        Button {
                            id: kml
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            text: qsTr("Load KML")
                            font.pointSize: 13
                            enabled: true
                            onClicked: {
                                map.createAndAddKmlLayer();
                            }
                        }
                    }
                }
            }


            MapForm{
                id: map
                Layout.preferredWidth: parent.width*0.9
                Layout.fillHeight: true

                MapGrid{
                    id: grid
                    anchors.fill: parent
                }

                RasterLoader{
                    id: loader
                    onRasterFileChosen: url => {
                        map.createAndAddRasterLayer(url);
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
                }
            }
        }
    }
}
