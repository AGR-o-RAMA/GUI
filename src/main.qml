// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: Screen.width
    height: Screen.height

    visible: true
    title: "Agroramads"

    Rectangle {
        width:  Screen.width
        height: Screen.height
        id: mainScreen
        MenuBar {
            id: menuBar
            width: parent.width

            Menu {
                title: qsTr("&File")
                Action { text: qsTr("&New...") }
                Action { text: qsTr("&Open...") }
                Action { text: qsTr("&Save") }
                Action { text: qsTr("Save &As...") }
                MenuSeparator { }
                Action { text: qsTr("&Quit") }
            }
            Menu {
                title: qsTr("&Edit")
                Action { text: qsTr("Cu&t") }
                Action { text: qsTr("&Copy") }
                Action { text: qsTr("&Paste") }
            }
            Menu {
                title: qsTr("&Views")
                Action { text: qsTr("&Show Tiles") }
                Action { text: qsTr("&Edit mode") }

            }
            Menu {
                title: qsTr("&Help")
                Action { text: qsTr("&About") }
            }
        }

        Plugin {
            id: mapPlugin
            name: "osm"
        }

        Row {
            id: row
            x: 0
            y: 0
            width: parent.width
            height: parent.height - menuBar.height
            anchors.top: menuBar.bottom

            Rectangle {
                width:  parent.width/8
                height: parent.height
                id: leftWindow

                CheckDelegate {
                    id: useCuda
                    width: 134
                    text: qsTr("use_cuda")
                    anchors.top: parent.top
                }
                CheckDelegate {
                    id: editMode
                    text: qsTr("Edit Mode")
                    anchors.top: useCuda.bottom

                }
            }


            Map {
                id: map
                anchors.fill: parent.Center
                width: parent.width * 20 / 24
                height: parent.height
                plugin: mapPlugin
                center: QtPositioning.coordinate(41.902782, 12.496366)
                zoomLevel: 14

                Button {
                    id: plusButton
                    x: 0.95 * parent.width
                    y: 0.8 * parent.height
                    width: 40
                    text: qsTr("+")
                }

                Button {
                    id: minusButton

                    width: 40
                    text: qsTr("-")
                    anchors.top: plusButton.bottom
                    anchors.left: plusButton.left
                    anchors.topMargin: 1
                }
            }
            Slider {
                id: slider
                width: parent.width / 24
                height: 971
                orientation: Qt.Vertical
                value: 0.5
            }


        }


    }

}

