#include "application_engine.h"

using namespace Esri::ArcGISRuntime;

ApplicationEngine::ApplicationEngine(QQmlApplicationEngine *parent) : QQmlApplicationEngine(parent){}

int ApplicationEngine::setup(QString api_key){
    // Add the import Path
    addImportPath(Esri::ArcGISRuntime::ArcGISRuntimeEnvironment::installDirectory() + "/sdk/linux/x64/qml");
    //Set the source
    load(QUrl("qrc:/qml/main.qml"));

    auto topLevelObject = rootObjects().value(0);
    auto window = qobject_cast<QQuickWindow*>(topLevelObject);
    if (!window)
    {
        qCritical("Error: Your root item has to be a Window.");
        return -1;
    }

    // Link c++ classes
    QQuickItem* map_view = topLevelObject->findChild<QQuickItem*>("mapView");
    QQmlContext* root = rootContext();
    TilesHandler* th = new TilesHandler(map_view);
    root -> setContextProperty("TilesHandler",th);
    MenuActions* menuActions = new MenuActions;
    root -> setContextProperty("MenuActions",menuActions);
    Settings* settings = new Settings;
    root -> setContextProperty("YamlSettings", settings);
    settings->api_key = api_key;
    rootContext()->setContextProperty("CurDirPath", QString(QDir::currentPath()));

    window -> show();
    return 0;
}


