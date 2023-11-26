/****************************************************************************
** Meta object code from reading C++ file 'operation.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/operation.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operation.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSOperationENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSOperationENDCLASS = QtMocHelpers::stringData(
    "Operation",
    "Value",
    "ActivateTiles",
    "SelectTile",
    "DeselectTile",
    "DeactivateTiles"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSOperationENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[10];
    char stringdata1[6];
    char stringdata2[14];
    char stringdata3[11];
    char stringdata4[13];
    char stringdata5[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSOperationENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSOperationENDCLASS_t qt_meta_stringdata_CLASSOperationENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Operation"
        QT_MOC_LITERAL(10, 5),  // "Value"
        QT_MOC_LITERAL(16, 13),  // "ActivateTiles"
        QT_MOC_LITERAL(30, 10),  // "SelectTile"
        QT_MOC_LITERAL(41, 12),  // "DeselectTile"
        QT_MOC_LITERAL(54, 15)   // "DeactivateTiles"
    },
    "Operation",
    "Value",
    "ActivateTiles",
    "SelectTile",
    "DeselectTile",
    "DeactivateTiles"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSOperationENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    4,   19,

 // enum data: key, value
       2, uint(Operation::ActivateTiles),
       3, uint(Operation::SelectTile),
       4, uint(Operation::DeselectTile),
       5, uint(Operation::DeactivateTiles),

       0        // eod
};

Q_CONSTINIT const QMetaObject Operation::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_CLASSOperationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSOperationENDCLASS,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSOperationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Operation, std::true_type>
    >,
    nullptr
} };

QT_WARNING_POP
