#include "tile.h"

Tile::Tile(QPoint centroid_px, GeoCoordinate centroid_coord) : centroid_px(centroid_px), centroid_coord(centroid_coord), selected(false) {}

Tile::Tile(QPoint centroid_px, GeoCoordinate centroid_coord, bool selected) : centroid_px(centroid_px), centroid_coord(centroid_coord), selected(selected) {}

void Tile::select() { this->selected = true; }

void Tile::deselect() { this->selected = false; }

bool Tile::isSelected() const { return this->selected; }

GeoCoordinate Tile::getCentroid_coord() const { return this->centroid_coord; }
