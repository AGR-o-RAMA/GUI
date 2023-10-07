#ifndef COORD_INPUT_H
#define COORD_INPUT_H

#include <QInputDialog>
#include <QObject>
#include <QFile>
#include <QLabel>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QComboBox>
#include <QPushButton>
#include "ArcGISRuntimeEnvironment.h"
#include "Point.h"

class CoordInput : public QDialog
{
    Q_OBJECT

private:
    QPointF point_;
    QList<QLineEdit*> fields;

public:
    CoordInput(QDialog* parent = nullptr);
    Q_INVOKABLE QPointF getPoint();
};

#endif // COORD_INPUT_H
