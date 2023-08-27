
#ifndef TILE_H
#define TILE_H

#include <utility>
#include <inttypes.h>
#include <QGeoCoordinate>
#include <QPoint>

using u16 = uint16_t;

class Tile
{
private:
    QPoint centroid_px;
    QGeoCoordinate centroid_coord;
    bool selected;
public:
    Tile(QPoint centroid_px, QGeoCoordinate centroid_coord);
    Tile(QPoint centroid_px, QGeoCoordinate centroid_coord, bool selected);
    void select();
    void deselect();
    bool isSelected();
};

#endif // TILE_H
