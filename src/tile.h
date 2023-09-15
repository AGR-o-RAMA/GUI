
#ifndef TILE_H
#define TILE_H

#include <utility>
#include "geoCoordinate.h"

class Tile
{
private:
    QPoint centroid_px;
    GeoCoordinate centroid_coord;
    bool selected;
public:
    Tile(QPoint centroid_px, GeoCoordinate centroid_coord);
    Tile(QPoint centroid_px, GeoCoordinate centroid_coord, bool selected);
    void select();
    void deselect();
    bool isSelected() const;
    GeoCoordinate getCentroid_coord() const;
};

#endif // TILE_H
