#include "tile.h"

Tile::Tile(QPoint centroid_px, QGeoCoordinate centroid_coord): centroid_px(centroid_px), centroid_coord(centroid_coord) {}

Tile::Tile(QPoint centroid_px, QGeoCoordinate centroid_coord, bool selected): centroid_px(centroid_px), centroid_coord(centroid_coord), selected(selected) {}

void Tile::select() {this->selected = true;}

void Tile::deselect() {this->selected = false;}

bool Tile::isSelected() const {return this->selected;}

QGeoCoordinate Tile::getCentroid_coord() const {return this->centroid_coord;}

