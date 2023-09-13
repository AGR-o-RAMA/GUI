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
                Layout.fillHeight: true
                Layout.preferredWidth: row.width*0.05
                id: leftWindow

                spacing: 100

                CheckDelegate {
                    id: editMode
                    text: qsTr("Edit Mode")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    onCheckedChanged: {
                        if(checkState == Qt.Unchecked){
                            meters.visible = false;
                            map.enableDragDrop();
                            slider.visible = false;
                            generate.enabled = false;
                            grid.deactivate();
                        }
                        else if (checkState == Qt.Checked){
                            meters.visible = true;
                            map.disableDragDrop();
                            slider.visible = true;
                            generate.enabled = true;
                            grid.activate();
                        }
                    }
                }

                Button{
                    id: generate
                    text: qsTr("Generate Orthomap")
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    enabled: false
                    onClicked: {
                        TilesHandler.generateCsv();
                    }
                }

                Button {
                    id: tif
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: qsTr("Load TIF File")
                    enabled: true
                    onClicked: {
                        map.loadTif();
                    }
                }

                CheckDelegate {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    id: useCuda
                    text: qsTr("Use Cuda")
                }

                TextEdit {
                    id: meters
                    readOnly: true
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    visible: false
                    color: "white"
                    font.pointSize: 15
                    text: qsTr("")
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
            }

            Rectangle{
               id: slider
               Layout.fillHeight: true
               Layout.preferredWidth: row.width*0.02
               visible: false

               Slider {
                   height: parent.height*0.9
                   orientation: Qt.Vertical
                   anchors.horizontalCenter: parent.horizontalCenter
                   anchors.verticalCenter: parent.verticalCenter
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
