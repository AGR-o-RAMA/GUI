#ifndef TILESHANDLER_H
#define TILESHANDLER_H

#include <QObject>
#include <QMetaObject>
#include <QQuickItem>
#include "tile.h"

class TilesHandler : public QObject
{
    Q_OBJECT

private:
    std::vector<std::vector<Tile>> tilesMatrix;
    u16 size_px;
    QQuickItem* map_view;
    std::pair<u16,u16> pixelToIdx(u16 x_px, u16 y_px);

public:
    explicit TilesHandler(QQuickItem *map_view, QObject *parent = nullptr);

signals:

public slots:
    void generateGrid(uint size, uint map_w, uint map_h);

    // All the following methods require the pixel coordinates of the tile top left corner
    void selectTile(uint x_px, uint y_px);
    void deselectTile(uint x_px, uint y_px);
    bool isTileSelected(uint x_px, uint y_px);
    void reset();
};

#endif // TILESHANDLER_H
