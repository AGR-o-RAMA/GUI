import QtQuick
import QtQuick.Controls


Rectangle {
    width: parent.width
    height: parent.height
    color: "black"
    opacity: 0.7
    z: 9999
    visible: false

    MouseArea {
        anchors.fill: parent
        onClicked: {}
    }

    Rectangle {

        property int radius: 350
        property bool useDouble: false

        property int _innerRadius: radius * 0.7
        property int _circleRadius: (radius - _innerRadius) * 0.5

        id: root
        width: radius * 2
        height: radius * 2
        color: "transparent"

        anchors.centerIn: parent

        Repeater {
            id: repeater
            model: root.useDouble ? 10 : 4
            delegate: Component {
                Rectangle {
                    property int _currentAngle: _getStartAngle()

                    id: rect
                    width: _getWidth()
                    height: width
                    radius: width
                    transformOrigin: Item.Center
                    x: root._getPosOnCircle(_currentAngle).x
                    y: root._getPosOnCircle(_currentAngle).y
                    antialiasing: true

                    SequentialAnimation {
                        id: anim
                        loops: Animation.Infinite

                        NumberAnimation {
                            target: rect
                            property: "_currentAngle"
                            duration: root.useDouble ? 1800 : 1000
                            from: rect._getStartAngle()
                            to: 360 + rect._getStartAngle()
                            easing.type: Easing.OutQuad
                        }

                        PauseAnimation { duration: 500 }
                    }


                    function playAnimation() {
                        if (anim.running == false) {
                            anim.start();
                        }
                    }


                    function _getStartAngle() {
                        var ang = 90;
                        if (root.useDouble) {
                            ang = index < 5 ? 90 : 270;
                        }

                        return ang;
                    }

                    function _getWidth() {
                        var w = (root._circleRadius) * 0.5 * (repeater.model - index);
                        if (root.useDouble) {
                            w = (root._circleRadius) * 0.5 * ((repeater.model / 2) - Math.abs(repeater.model / 2 - index))
                        }

                        return w;
                    }
                }
            }
        }

        Timer {
            property int _circleIndex: 0

            interval: 100
            repeat: true
            onTriggered: {
                var maxIndex = root.useDouble ? repeater.model / 2 : repeater.model;
                if (_circleIndex === maxIndex) {
                    stop();
                }
                else {
                    repeater.itemAt(_circleIndex).playAnimation();
                    if (root.useDouble) {
                        repeater.itemAt(repeater.model - _circleIndex - 1).playAnimation();
                    }

                    _circleIndex++;
                }
            }
            Component.onCompleted: start()
        }

        function _toRadian(degree) {
            return (degree * 3.14159265) / 180.0;
        }

        function _getPosOnCircle(angleInDegree) {
            var centerX = root.width / 2, centerY = root.height / 2;
            var posX = 0, posY = 0;

            posX = centerX + root._innerRadius * Math.cos(_toRadian(angleInDegree));
            posY = centerY - root._innerRadius * Math.sin(_toRadian(angleInDegree));
            return Qt.point(posX, posY);
        }
    }

    Text {
        id: loadingText
        text: qsTr("Generating Orthomap...\nThis process may take several hours")
        color: "white"
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        font.pixelSize: 24
    }
}
