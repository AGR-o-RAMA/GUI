
#ifndef TILE_H
#define TILE_H

#include <utility>
#include <QGeoCoordinate>
#include <QPoint>

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
    bool isSelected() const;
    QGeoCoordinate getCentroid_coord() const;
};

#endif // TILE_H
