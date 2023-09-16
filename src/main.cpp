#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QDir>
#include <QtPlugin>
#include <QQmlContext>
#include <QQuickItem>
#include <QQuickView>
#include <QCommandLineParser>
#include <QQmlEngine>
#include "ArcGISRuntimeEnvironment.h"

#include "tilesHandler.h"
#include "menuActions.h"
#include "operation.h"
#include "processfactory.h"

//------------------------------------------------------------------------------

using namespace Esri::ArcGISRuntime;

int main(int argc, char *argv[])
{
    qDebug() << "Initializing application";

    QApplication app(argc, argv);

    qmlRegisterType<ProcessFactory>("ProcessFactory", 1, 0, "ProcessFactory");

    app.setOrganizationName("sap");
    app.setOrganizationDomain("sap");

    const QString apiKey = QString("AAPKaee6e86df5054d838ca028100d788f8b7C1W1Equqmh_6BP-VdUGO7bZv2T70-GHdf4JbvDUP7IqRV9azY6QpRtjmZJENMP2");
    if (apiKey.isEmpty())
    {
        qWarning() << "Use of Esri location services, including basemaps, requires" <<
            "you to authenticate with an ArcGIS identity or set the API Key property.";
    }
    else
    {
        ArcGISRuntimeEnvironment::setApiKey(apiKey);
    }

    qmlRegisterUncreatableType<Operation>("agrorama_lib", 1, 0, "Operation", "Not creatable as it is an enum type");

    // Initialize application view
    QQmlApplicationEngine engine;
    // Add the import Path
    engine.addImportPath(Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::installDirectory() + "/sdk/linux/x64/qml");
    //Set the source
    engine.load(QUrl("qrc:/qml/main.qml"));

    auto topLevelObject = engine.rootObjects().value(0);
    auto window = qobject_cast<QQuickWindow*>(topLevelObject);
    if (!window)
    {
        qCritical("Error: Your root item has to be a Window.");

        return -1;
    }

    // Link c++ classes
    QQuickItem* map_view = topLevelObject->findChild<QQuickItem*>("mapView");
    QQmlContext* root = engine.rootContext();
    TilesHandler* th = new TilesHandler(map_view);
    root -> setContextProperty("TilesHandler",th);
    MenuActions* menuActions = new MenuActions;
    root -> setContextProperty("MenuActions",menuActions);

    window->show();
    return app.exec();
}

//------------------------------------------------------------------------------
