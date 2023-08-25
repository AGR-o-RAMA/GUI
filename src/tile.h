
#ifndef TILE_H
#define TILE_H

#include <utility>
#include <inttypes.h>

using u16 = uint16_t;

class Tile
{
private:
    std::pair < u16, u16 > centroid_px;
    bool selected;
public:
    Tile(u16 x, u16 y);
    Tile(u16 x, u16 y, bool selected);
    void select();
    void deselect();
    bool isSelected();
};

#endif // TILE_H
