// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: Screen.width
    height: Screen.height

    visible: true
    title: "Agroramads"

    ColumnLayout {
        width:  Screen.width
        height: Screen.height
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

        RowLayout {
            id: row
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing:0

            ColumnLayout {
                Layout.fillHeight: true
                Layout.preferredWidth: row.width*0.2
                Layout.alignment: Qt.AlignLeft
                id: leftWindow
                spacing:20

                CheckDelegate {
                    id: editMode
                    Layout.alignment: Qt.AlignTop | Qt.AlignCenter
                    text: qsTr("Edit Mode")
                    onCheckedChanged: {
                        if(checkState == Qt.Unchecked){
                            meters.text = "";
                            plusButton.visible = true;
                            minusButton.visible = true;
                            slider.visible = false;
                            grid.operation = 3;
                            grid.requestPaint();
                        }
                        else if (checkState == Qt.Checked){
                            plusButton.visible = false;
                            minusButton.visible = false;
                            slider.visible = true;
                            map.gesture.enabled = false;
                            grid.operation = 0;
                            grid.requestPaint();
                        }
                    }
                }

                Rectangle{

                    id: metersBox
                    Layout.alignment: Qt.AlignTop | Qt.AlignCenter
                    Layout.fillWidth: true
                    Layout.preferredHeight: parent.height*0.12

                    Text {
                        id: meters
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 15
                        text: qsTr("")
                    }
                }

                CheckDelegate {
                    id: useCuda
                    Layout.alignment: Qt.AlignTop | Qt.AlignCenter
                    text: qsTr("Use Cuda")
                }

                Button{
                    id: generate
                    text: qsTr("Generate Ortomap")
                    Layout.alignment: Qt.AlignBottom | Qt.AlignCenter
                    Layout.fillWidth: true
                    Layout.preferredHeight: 50
                }

            }


            Map {
                id: map
                objectName: "mapView"

                Layout.fillHeight: true
                Layout.preferredWidth: row.width*0.85
                Layout.alignment: Qt.AlignCenter

                plugin: mapPlugin
                center: QtPositioning.coordinate(41.902782, 12.496366)
                zoomLevel: 14
                gesture.enabled: true

                function generateCoordinates(point){
                    return map.toCoordinate(point, false);
                }

                Button {
                    id: plusButton
                    x: 0.95 * parent.width
                    y: 0.8 * parent.height
                    z: 1
                    width: 40
                    text: qsTr("+")
                    onPressed: if(map.gesture.enabled) ++map.zoomLevel;
                }

                Button {
                    id: minusButton
                    z: 1
                    width: 40
                    text: qsTr("-")
                    anchors.top: plusButton.bottom
                    anchors.left: plusButton.left
                    anchors.topMargin: 1
                    onPressed: if(map.gesture.enabled) --map.zoomLevel;
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

                        property int wgrid: 100
                        property int operation: 0 // 0 -> tiles 1 -> mark 2 -> unmark 3 -> clean
                        property int rectX: 0;
                        property int rectY: 0;

                        property int gridLineWidth: 1;

                        onPaint: {
                            if(map.gesture.enabled)
                               return;

                            const ctx = getContext("2d")
                            if(operation == 0){
                                //map.generateCoordinates();
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
                                meters.text = "Tiles size: "+tileshandler.getSize_m().toFixed(2)+" m";
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
                            else if(operation == 3){
                                ctx.reset()
                                tileshandler.reset();
                                map.gesture.enabled = true;
                            }
                        }
                    }
            }
            Rectangle{
                id: sliderBox
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignRight
                Layout.preferredWidth: row.width*0.03

                Slider {
                    id: slider
                    z:1
                    visible: false

                    width:parent.width
                    height:parent.height*0.9

                    orientation: Qt.Vertical
                    from: 20
                    to: 300
                    value: grid.wgrid
                    onMoved: {
                        grid.wgrid = value;
                        grid.operation = 0;
                        grid.requestPaint();
                    }

                }
            }


        }


    }

}

