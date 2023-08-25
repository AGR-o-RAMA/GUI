#include "tile.h"

Tile::Tile(u16 x, u16 y) : centroid_px(std::make_pair(x,y)), selected(false) {}

Tile::Tile(u16 x, u16 y, bool selected) : centroid_px(std::make_pair(x,y)), selected(selected) {}

void Tile::select() {this->selected = true;}

void Tile::deselect() {this->selected = false;}

bool Tile::isSelected() {return this->selected;}
