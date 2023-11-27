/****************************************************************************
** Meta object code from reading C++ file 'settings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/settings.h"
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
#error "The header file 'settings.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSettingsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSettingsENDCLASS = QtMocHelpers::stringData(
    "Settings",
    "setUse_cuda",
    "",
    "newUse_cuda",
    "getUse_cuda",
    "getProject_path",
    "getYamlParamsName",
    "getGuiSubDir",
    "getYamlSaveName",
    "getOutputPath",
    "dumpToYaml",
    "path",
    "tileSize",
    "pathJoin",
    "std::vector<QString>",
    "paths"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSettingsENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[12];
    char stringdata5[16];
    char stringdata6[18];
    char stringdata7[13];
    char stringdata8[16];
    char stringdata9[14];
    char stringdata10[11];
    char stringdata11[5];
    char stringdata12[9];
    char stringdata13[9];
    char stringdata14[21];
    char stringdata15[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSettingsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSettingsENDCLASS_t qt_meta_stringdata_CLASSSettingsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Settings"
        QT_MOC_LITERAL(9, 11),  // "setUse_cuda"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 11),  // "newUse_cuda"
        QT_MOC_LITERAL(34, 11),  // "getUse_cuda"
        QT_MOC_LITERAL(46, 15),  // "getProject_path"
        QT_MOC_LITERAL(62, 17),  // "getYamlParamsName"
        QT_MOC_LITERAL(80, 12),  // "getGuiSubDir"
        QT_MOC_LITERAL(93, 15),  // "getYamlSaveName"
        QT_MOC_LITERAL(109, 13),  // "getOutputPath"
        QT_MOC_LITERAL(123, 10),  // "dumpToYaml"
        QT_MOC_LITERAL(134, 4),  // "path"
        QT_MOC_LITERAL(139, 8),  // "tileSize"
        QT_MOC_LITERAL(148, 8),  // "pathJoin"
        QT_MOC_LITERAL(157, 20),  // "std::vector<QString>"
        QT_MOC_LITERAL(178, 5)   // "paths"
    },
    "Settings",
    "setUse_cuda",
    "",
    "newUse_cuda",
    "getUse_cuda",
    "getProject_path",
    "getYamlParamsName",
    "getGuiSubDir",
    "getYamlSaveName",
    "getOutputPath",
    "dumpToYaml",
    "path",
    "tileSize",
    "pathJoin",
    "std::vector<QString>",
    "paths"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingsENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x0a,    1 /* Public */,
       4,    0,   77,    2, 0x0a,    3 /* Public */,
       5,    0,   78,    2, 0x0a,    4 /* Public */,
       6,    0,   79,    2, 0x0a,    5 /* Public */,
       7,    0,   80,    2, 0x0a,    6 /* Public */,
       8,    0,   81,    2, 0x0a,    7 /* Public */,
       9,    0,   82,    2, 0x0a,    8 /* Public */,
      10,    2,   83,    2, 0x0a,    9 /* Public */,
      10,    1,   88,    2, 0x2a,   12 /* Public | MethodCloned */,
      13,    1,   91,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,   11,   12,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::QString, 0x80000000 | 14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject Settings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Settings, std::true_type>,
        // method 'setUse_cuda'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getUse_cuda'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getProject_path'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getYamlParamsName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getGuiSubDir'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getYamlSaveName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getOutputPath'
        QtPrivate::TypeAndForceComplete<QUrl, std::false_type>,
        // method 'dumpToYaml'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'dumpToYaml'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'pathJoin'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::vector<QString>, std::false_type>
    >,
    nullptr
} };

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setUse_cuda((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: { bool _r = _t->getUse_cuda();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getProject_path();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getYamlParamsName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getGuiSubDir();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getYamlSaveName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QUrl _r = _t->getOutputPath();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->dumpToYaml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2]))); break;
        case 8: _t->dumpToYaml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { QString _r = _t->pathJoin((*reinterpret_cast< std::add_pointer_t<std::vector<QString>>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
