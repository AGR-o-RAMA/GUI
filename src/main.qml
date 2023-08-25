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
                Action { text: qsTr("&New...")
                    onTriggered: print("OK")
                }
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
                    z: 1
                    width: 40
                    text: qsTr("+")
                    onPressed: ++map.zoomLevel;
                }

                Button {
                    id: minusButton
                    z: 1
                    width: 40
                    text: qsTr("-")
                    anchors.top: plusButton.bottom
                    anchors.left: plusButton.left
                    anchors.topMargin: 1
                    onPressed: --map.zoomLevel;
                }

                Canvas {

                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton

                        onClicked: {
                            if(mouse.button === Qt.RightButton){
                                grid.rectX = Math.floor(mouseX/grid.wgrid) * grid.wgrid;
                                grid.rectY = Math.floor(mouseY/grid.wgrid) * grid.wgrid;

                                grid.operation = 2;
                                grid.requestPaint();
                            }
                            else if (mouse.button === Qt.LeftButton){
                                grid.rectX = Math.floor(mouseX/grid.wgrid) * grid.wgrid;
                                grid.rectY = Math.floor(mouseY/grid.wgrid) * grid.wgrid;

                                grid.operation = 1;
                                grid.requestPaint();
                            }
                        }
                    }

                        id: grid
                        anchors.fill : parent

                        property int wgrid: 40
                        property int operation: 0 // 0 -> tiles 1 -> mark 2 -> unmark
                        property int rectX: 0;
                        property int rectY: 0;

                        property int gridLineWidth: 1;

                        onPaint: {
                            const ctx = getContext("2d")
                            if(operation == 0){
                                tileshandler.generateGrid(wgrid, map.width, map.height);
                                ctx.reset()
                                ctx.lineWidth = gridLineWidth
                                ctx.strokeStyle = "black"
                                ctx.beginPath()
                                var nrows = height/wgrid;
                                for(var i=0; i < nrows+1; i++){
                                    ctx.moveTo(0, wgrid*i);
                                    ctx.lineTo(width, wgrid*i);
                                }

                                var ncols = width/wgrid
                                for(var j=0; j < ncols+1; j++){
                                    ctx.moveTo(wgrid*j, 0);
                                    ctx.lineTo(wgrid*j, height);
                                }
                                ctx.closePath()
                                ctx.stroke()
                            }
                            else if(operation == 1 && !tileshandler.isTileSelected(rectX,rectY)){
                                rectX += gridLineWidth;
                                rectY += gridLineWidth;
                                const clippedW = wgrid - 2*gridLineWidth;

                                tileshandler.selectTile(rectX,rectY);

                                ctx.fillStyle = Qt.rgba(1, 0, 0, 0.15);
                                ctx.fillRect(rectX,rectY,clippedW,clippedW);
                            }
                            else if(operation == 2 && tileshandler.isTileSelected(rectX,rectY)){
                                rectX += gridLineWidth;
                                rectY += gridLineWidth;
                                const clippedW = wgrid - 2*gridLineWidth;

                                tileshandler.deselectTile(rectX,rectY);

                                ctx.clearRect(rectX,rectY,clippedW,clippedW);
                            }
                        }
                    }
            }
            Slider {
                id: slider
                width: parent.width / 24
                height: 971
                orientation: Qt.Vertical
                from: 20
                to: 300
                value: 100
                onMoved: {
                    grid.wgrid = value;
                    grid.operation = 0;
                    grid.requestPaint();
                }

            }


        }


    }

}

