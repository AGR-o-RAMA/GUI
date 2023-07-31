import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: Screen.width
    height: Screen.height
    visible: true

    Plugin {
        id: mapPlugin
        name: "osm" //"mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    Row {
        id: row
        x: 0
        y: 0
        width: Screen.width
        height: Screen.height
        Text {
            id: text1
            anchors.fill: parent.left
            width: parent.width/6
            height: parent.height
            text: qsTr("HELLOOOOOOOOOOOOOOOO")
            font.pixelSize: 18
        }
        Map {
            anchors.fill: parent.Center
            width: parent.width*2/3
            height: parent.height
            plugin: mapPlugin
            center: QtPositioning.coordinate(41.902782, 12.496366)
            zoomLevel: 14
        }
        Text {
            id: text2
            anchors.fill: parent.right
            width: parent.width/6
            height: parent.height
            text: qsTr("HELLOOOOOOOOOOOOOOOO")
            font.pixelSize: 18
        }
    }

}
