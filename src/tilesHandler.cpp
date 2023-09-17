#include "tilesHandler.h"

#include <QDebug>
#include <QQmlProperty>

TilesHandler::TilesHandler(QQuickItem *map_view, QObject *parent)
    : QObject{parent}, map_view(map_view) {}

std::pair<u16, u16> TilesHandler::pixelToIdx(u16 x_px, u16 y_px)
{
    uint half_size = this->size_px/2;
    u16 c = (x_px + half_size)/this->size_px;
    u16 r = (y_px + half_size)/this->size_px;
    return std::make_pair(r,c);
}

float TilesHandler::getSize_m() {return size_m;}

void TilesHandler::generateGrid(uint size, uint map_w, uint map_h){

    this->tilesMatrix.clear();

    this->size_px = size;

    uint half_size = size/2;
    for(uint r = 0; r < map_h; r+=size){
        std::vector<Tile> row;
        for(uint c = 0; c < map_w; c+=size){
            QPoint point(c+half_size, r+half_size);
            QVariant res;
            QMetaObject::invokeMethod(map_view, "generateCoordinates", Q_RETURN_ARG(QVariant, res), Q_ARG(QVariant, point));
            GeoCoordinate coord(res);

            Tile t(point, coord);

            row.push_back(t);
        }
        this->tilesMatrix.push_back(row);
    }

    GeoCoordinate p1 = this->tilesMatrix[0][0].getCentroid_coord();
    GeoCoordinate p2 = this->tilesMatrix[0][1].getCentroid_coord();

    this->size_m = p1.distanceTo(p2);
}

void TilesHandler::selectTile(uint x_px, uint y_px)
{
    std::pair<u16, u16> idx = this->pixelToIdx(x_px, y_px);
    this->tilesMatrix[idx.first][idx.second].select();
}

void TilesHandler::deselectTile(uint x_px, uint y_px)
{
    std::pair<u16, u16> idx = this->pixelToIdx(x_px, y_px);
    this->tilesMatrix[idx.first][idx.second].deselect();
}

bool TilesHandler::isTileSelected(uint x_px, uint y_px)
{
    std::pair<u16, u16> idx = this->pixelToIdx(x_px, y_px);
    return tilesMatrix[idx.first][idx.second].isSelected();
}

void TilesHandler::reset()
{
    this->tilesMatrix.clear();
}

void TilesHandler::generateCsv()
{
    std::ofstream f;
    f.open("test.csv", std::ios::trunc);

    u16 rows = this->tilesMatrix.size();
    assert(rows > 0);
    u16 cols = this->tilesMatrix[0].size();
    assert(cols > 0);

    f << "metrics_x, metrics_y, coordinate_lat, coordinate_long\n";

    for(int r = rows-1; r >= 0; --r){
        for(int c = 0; c < cols; ++c){
            if(this->tilesMatrix[r][c].isSelected()){
                u16 shift_r = rows-r-1;
                GeoCoordinate centroid = this->tilesMatrix[r][c].getCentroid_coord();
                f << c << ", "
                  << shift_r << ", "
                  << centroid.latitude() << ", "
                  << centroid.longitude()
                  << "\n";
            }
        }
    }
    f.close();
}


