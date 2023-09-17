#include <QObject>
#include <QMetaObject>
#include <QQuickItem>

#ifndef OPERATION_H
#define OPERATION_H

class Operation
{
    Q_GADGET
public:
    enum Value {
        ActivateTiles,
        SelectTile,
        DeselectTile,
        DeactivateTiles
    };
    Q_ENUM(Value)

private:
    explicit Operation();
};

#endif // OPERATION_H
