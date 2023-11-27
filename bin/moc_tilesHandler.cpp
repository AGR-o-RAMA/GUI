/****************************************************************************
** Meta object code from reading C++ file 'tilesHandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tilesHandler.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tilesHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTilesHandlerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTilesHandlerENDCLASS = QtMocHelpers::stringData(
    "TilesHandler",
    "generateGrid",
    "",
    "size",
    "map_w",
    "map_h",
    "selectTile",
    "x_px",
    "y_px",
    "deselectTile",
    "isTileSelected",
    "reset",
    "generateCsv",
    "getSize_m"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTilesHandlerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[6];
    char stringdata6[11];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[13];
    char stringdata10[15];
    char stringdata11[6];
    char stringdata12[12];
    char stringdata13[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTilesHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTilesHandlerENDCLASS_t qt_meta_stringdata_CLASSTilesHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "TilesHandler"
        QT_MOC_LITERAL(13, 12),  // "generateGrid"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "size"
        QT_MOC_LITERAL(32, 5),  // "map_w"
        QT_MOC_LITERAL(38, 5),  // "map_h"
        QT_MOC_LITERAL(44, 10),  // "selectTile"
        QT_MOC_LITERAL(55, 4),  // "x_px"
        QT_MOC_LITERAL(60, 4),  // "y_px"
        QT_MOC_LITERAL(65, 12),  // "deselectTile"
        QT_MOC_LITERAL(78, 14),  // "isTileSelected"
        QT_MOC_LITERAL(93, 5),  // "reset"
        QT_MOC_LITERAL(99, 11),  // "generateCsv"
        QT_MOC_LITERAL(111, 9)   // "getSize_m"
    },
    "TilesHandler",
    "generateGrid",
    "",
    "size",
    "map_w",
    "map_h",
    "selectTile",
    "x_px",
    "y_px",
    "deselectTile",
    "isTileSelected",
    "reset",
    "generateCsv",
    "getSize_m"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTilesHandlerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   56,    2, 0x0a,    1 /* Public */,
       6,    2,   63,    2, 0x0a,    5 /* Public */,
       9,    2,   68,    2, 0x0a,    8 /* Public */,
      10,    2,   73,    2, 0x0a,   11 /* Public */,
      11,    0,   78,    2, 0x0a,   14 /* Public */,
      12,    0,   79,    2, 0x0a,   15 /* Public */,
      13,    0,   80,    2, 0x0a,   16 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    7,    8,
    QMetaType::Bool, QMetaType::UInt, QMetaType::UInt,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Float,

       0        // eod
};

Q_CONSTINIT const QMetaObject TilesHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTilesHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTilesHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTilesHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TilesHandler, std::true_type>,
        // method 'generateGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'selectTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'deselectTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'isTileSelected'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'reset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateCsv'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getSize_m'
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void TilesHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TilesHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->generateGrid((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[3]))); break;
        case 1: _t->selectTile((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 2: _t->deselectTile((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 3: { bool _r = _t->isTileSelected((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->reset(); break;
        case 5: _t->generateCsv(); break;
        case 6: { float _r = _t->getSize_m();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *TilesHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TilesHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTilesHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TilesHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
