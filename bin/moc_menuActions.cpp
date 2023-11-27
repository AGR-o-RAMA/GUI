/****************************************************************************
** Meta object code from reading C++ file 'menuActions.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/menuActions.h"
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
#error "The header file 'menuActions.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMenuActionsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMenuActionsENDCLASS = QtMocHelpers::stringData(
    "MenuActions",
    "newProject",
    "",
    "QQuickItem*",
    "leftWindow",
    "openProject",
    "onFinishButtonClicked",
    "onNextButtonClicked",
    "setSettings",
    "onCreateFinished"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMenuActionsENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[11];
    char stringdata5[12];
    char stringdata6[22];
    char stringdata7[20];
    char stringdata8[12];
    char stringdata9[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMenuActionsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMenuActionsENDCLASS_t qt_meta_stringdata_CLASSMenuActionsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "MenuActions"
        QT_MOC_LITERAL(12, 10),  // "newProject"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 11),  // "QQuickItem*"
        QT_MOC_LITERAL(36, 10),  // "leftWindow"
        QT_MOC_LITERAL(47, 11),  // "openProject"
        QT_MOC_LITERAL(59, 21),  // "onFinishButtonClicked"
        QT_MOC_LITERAL(81, 19),  // "onNextButtonClicked"
        QT_MOC_LITERAL(101, 11),  // "setSettings"
        QT_MOC_LITERAL(113, 16)   // "onCreateFinished"
    },
    "MenuActions",
    "newProject",
    "",
    "QQuickItem*",
    "leftWindow",
    "openProject",
    "onFinishButtonClicked",
    "onNextButtonClicked",
    "setSettings",
    "onCreateFinished"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMenuActionsENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       5,    1,   53,    2, 0x0a,    3 /* Public */,
       6,    0,   56,    2, 0x0a,    5 /* Public */,
       7,    0,   57,    2, 0x0a,    6 /* Public */,
       8,    0,   58,    2, 0x0a,    7 /* Public */,
       9,    0,   59,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MenuActions::staticMetaObject = { {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSMenuActionsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMenuActionsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMenuActionsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MenuActions, std::true_type>,
        // method 'newProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QQuickItem *, std::false_type>,
        // method 'openProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QQuickItem *, std::false_type>,
        // method 'onFinishButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNextButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCreateFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MenuActions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MenuActions *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newProject((*reinterpret_cast< std::add_pointer_t<QQuickItem*>>(_a[1]))); break;
        case 1: _t->openProject((*reinterpret_cast< std::add_pointer_t<QQuickItem*>>(_a[1]))); break;
        case 2: _t->onFinishButtonClicked(); break;
        case 3: _t->onNextButtonClicked(); break;
        case 4: _t->setSettings(); break;
        case 5: _t->onCreateFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QQuickItem* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MenuActions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MenuActions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMenuActionsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int MenuActions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNewWizardPageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNewWizardPageENDCLASS = QtMocHelpers::stringData(
    "NewWizardPage",
    "sanityCheckPassedSignal",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNewWizardPageENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[14];
    char stringdata1[24];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNewWizardPageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNewWizardPageENDCLASS_t qt_meta_stringdata_CLASSNewWizardPageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "NewWizardPage"
        QT_MOC_LITERAL(14, 23),  // "sanityCheckPassedSignal"
        QT_MOC_LITERAL(38, 0)   // ""
    },
    "NewWizardPage",
    "sanityCheckPassedSignal",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNewWizardPageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NewWizardPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWizardPage::staticMetaObject>(),
    qt_meta_stringdata_CLASSNewWizardPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNewWizardPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNewWizardPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NewWizardPage, std::true_type>,
        // method 'sanityCheckPassedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NewWizardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewWizardPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sanityCheckPassedSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewWizardPage::*)();
            if (_t _q_method = &NewWizardPage::sanityCheckPassedSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *NewWizardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewWizardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNewWizardPageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int NewWizardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NewWizardPage::sanityCheckPassedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS = QtMocHelpers::stringData(
    "SettingsWizardPage",
    "sanitySettingsCheckPassedSignal",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[19];
    char stringdata1[32];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS_t qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "SettingsWizardPage"
        QT_MOC_LITERAL(19, 31),  // "sanitySettingsCheckPassedSignal"
        QT_MOC_LITERAL(51, 0)   // ""
    },
    "SettingsWizardPage",
    "sanitySettingsCheckPassedSignal",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSettingsWizardPageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SettingsWizardPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWizardPage::staticMetaObject>(),
    qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSettingsWizardPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SettingsWizardPage, std::true_type>,
        // method 'sanitySettingsCheckPassedSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SettingsWizardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsWizardPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sanitySettingsCheckPassedSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsWizardPage::*)();
            if (_t _q_method = &SettingsWizardPage::sanitySettingsCheckPassedSignal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *SettingsWizardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsWizardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSettingsWizardPageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int SettingsWizardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SettingsWizardPage::sanitySettingsCheckPassedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
