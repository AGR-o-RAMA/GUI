#include "tileshandler.h"

#include <QDebug>
#include <QQmlProperty>

TilesHandler::TilesHandler(QObject *parent)
    : QObject{parent}
{

}

std::pair<u16, u16> TilesHandler::pixelToIdx(u16 x_px, u16 y_px)
{
    uint half_size = this->size_px/2;
    u16 c = (x_px + half_size)/this->size_px;
    u16 r = (y_px + half_size)/this->size_px;
    return std::make_pair(r,c);
}

void TilesHandler::generateGrid(uint size, uint map_w, uint map_h){
    this->tilesMatrix.clear();

    this->size_px = size;
    uint half_size = size/2;
    for(uint r = 0; r < map_h; r+=size){
        std::vector<Tile> row;
        for(uint c = 0; c < map_w; c+=size){
            Tile t(c+half_size, r+half_size);
            row.push_back(t);
        }
        this->tilesMatrix.push_back(row);
    }
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


