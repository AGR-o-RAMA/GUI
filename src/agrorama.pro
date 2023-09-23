#-------------------------------------------------
#  Copyright 2023 ESRI
#
#  All rights reserved under the copyright laws of the United States
#  and applicable international laws, treaties, and conventions.
#
#  You may freely redistribute and use this sample code, with or
#  without modification, provided you include the original copyright
#  notice and use restrictions.
#
#  See the Sample code usage restrictions document for further information.
#-------------------------------------------------

TEMPLATE = app

CONFIG += c++17

# additional modules are pulled in via arcgisruntime.pri
QT += widgets
QT += opengl qml quick
QT += core

TARGET = agrorama

lessThan(QT_MAJOR_VERSION, 6) {
    error("$$TARGET requires Qt 6.5.1")
}

equals(QT_MAJOR_VERSION, 6) {
    lessThan(QT_MINOR_VERSION, 5) {
        error("$$TARGET requires Qt 6.5.1")
    }
	equals(QT_MINOR_VERSION, 5) : lessThan(QT_PATCH_VERSION, 1) {
		error("$$TARGET requires Qt 6.5.1")
	}
}

ARCGIS_RUNTIME_VERSION = 200.2.0
include($$PWD/arcgisruntime.pri)

LIBS += -lyaml-cpp

HEADERS += \
    api_key.h \
    application_engine.h \
    geoCoordinate.h \
    menuActions.h \
    operation.h \
    processfactory.h \
    settings.h \
    tile.h \
    tilesHandler.h

SOURCES += \
    api_key.cpp \
    application_engine.cpp \
    main.cpp \
    menuActions.cpp \
    processfactory.cpp \
    settings.cpp \
    tile.cpp \
    tilesHandler.cpp

RESOURCES += \
    qml/qml.qrc \
    Resources/Resources.qrc

#-------------------------------------------------------------------------------

win32 {
    include (Win/Win.pri)
}

macx {
    include (Mac/Mac.pri)
}

ios {
    include (iOS/iOS.pri)
}

android {
    include (Android/Android.pri)
}
