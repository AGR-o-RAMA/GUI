#ifndef APPLICATION_ENGINE_H
#define APPLICATION_ENGINE_H

#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>
#include "tilesHandler.h"
#include "menuActions.h"
#include "operation.h"
#include "coord_input.h"

#include "ArcGISRuntimeEnvironment.h"

class ApplicationEngine : public QQmlApplicationEngine
{
    Q_OBJECT

public:
    ApplicationEngine(QQmlApplicationEngine *parent = nullptr);

public slots:
    int setup(QString api_key);
};

#endif // APPLICATION_ENGINE_H
