import QtQuick
import Esri.ArcGISRuntime
import agrorama_lib

Item {
    id: root

    Canvas {
        id: grid
        anchors.fill : parent
        property int wgrid: 100
        property int operation: Operation.DeactivateTiles
        property int rectX: 0;
        property int rectY: 0;
        property int gridLineWidth: 1;


        onPaint: {
            const ctx = getContext("2d")
            if(operation === Operation.ActivateTiles){
                //map.generateCoordinates();
                gridMouse.enabled = true;
                TilesHandler.generateGrid(wgrid, parent.width, parent.height);
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
                meters.text = "Tiles size \n"+ TilesHandler.getSize_m().toFixed(2)+" m";
            }
            else if(operation === Operation.SelectTile && !TilesHandler.isTileSelected(rectX,rectY)){
                rectX += gridLineWidth;
                rectY += gridLineWidth;
                const clippedW = wgrid - 2*gridLineWidth;

                TilesHandler.selectTile(rectX,rectY);

                ctx.fillStyle = Qt.rgba(1, 0, 0, 0.2);
                ctx.fillRect(rectX,rectY,clippedW,clippedW);
            }
            else if(operation === Operation.DeselectTile && TilesHandler.isTileSelected(rectX,rectY)){
                rectX += gridLineWidth;
                rectY += gridLineWidth;
                const clippedW = wgrid - 2*gridLineWidth;

                TilesHandler.deselectTile(rectX,rectY);

                ctx.clearRect(rectX,rectY,clippedW,clippedW);
            }
            else if(operation === Operation.DeactivateTiles){
                ctx.reset()
                TilesHandler.reset();
                gridMouse.enabled = false;
                meters.text = "Tiles size \n";
            }
        }

        MouseArea {
            id: gridMouse
            enabled: false;
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            onClicked: (mouse) => {
                mouse.accepted = false
               if(mouse.button === Qt.RightButton){
                   grid.rectX = Math.floor(mouseX/grid.wgrid) * grid.wgrid;
                   grid.rectY = Math.floor(mouseY/grid.wgrid) * grid.wgrid;

                   grid.operation = Operation.DeselectTile;
                   grid.requestPaint();
               }
               else if (mouse.button === Qt.LeftButton){
                   grid.rectX = Math.floor(mouseX/grid.wgrid) * grid.wgrid;
                   grid.rectY = Math.floor(mouseY/grid.wgrid) * grid.wgrid;

                   grid.operation = Operation.SelectTile;
                   grid.requestPaint();
               }
            }
        }
    }

    function deactivate(){
        grid.operation = Operation.DeactivateTiles;
        grid.requestPaint();
    }

    function activate(){
        grid.operation = Operation.ActivateTiles;
        grid.requestPaint();
    }

    function getWidth(){
        return grid.wgrid;
    }

    function setWidth(value){
        grid.wgrid = value;
        grid.operation = Operation.ActivateTiles;
        grid.requestPaint();
    }
}
