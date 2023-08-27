#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QQmlComponent>
#include <QMetaObject>
#include <QQuickItem>
#include <iostream>
#include "tileshandler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Agrorama-mockup_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);



    QObject *root1 = engine.rootObjects().first();
    QQuickItem *map_view = root1->findChild<QQuickItem*>("mapView");

//    QVariant result;
//    QVariant msg = "ok";
//    QMetaObject::invokeMethod(map_view, "generateCoordinates", Q_RETURN_ARG(QVariant, result), Q_ARG(QVariant, msg));


    QQmlContext* root = engine.rootContext();
    TilesHandler* th = new TilesHandler(map_view);
    root->setContextProperty("tileshandler",th);

    return app.exec();
}
