/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Bryla3D/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[19];
    char stringdata5[19];
    char stringdata6[19];
    char stringdata7[14];
    char stringdata8[14];
    char stringdata9[14];
    char stringdata10[11];
    char stringdata11[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 10),  // "paintEvent"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 12),  // "QPaintEvent*"
        QT_MOC_LITERAL(36, 18),  // "przesuniecieX_slot"
        QT_MOC_LITERAL(55, 18),  // "przesuniecieY_slot"
        QT_MOC_LITERAL(74, 18),  // "przesuniecieZ_slot"
        QT_MOC_LITERAL(93, 13),  // "rotacjaX_slot"
        QT_MOC_LITERAL(107, 13),  // "rotacjaY_slot"
        QT_MOC_LITERAL(121, 13),  // "rotacjaZ_slot"
        QT_MOC_LITERAL(135, 10),  // "skala_slot"
        QT_MOC_LITERAL(146, 10)   // "Reset_slot"
    },
    "MainWindow",
    "paintEvent",
    "",
    "QPaintEvent*",
    "przesuniecieX_slot",
    "przesuniecieY_slot",
    "przesuniecieZ_slot",
    "rotacjaX_slot",
    "rotacjaY_slot",
    "rotacjaZ_slot",
    "skala_slot",
    "Reset_slot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x08,    1 /* Private */,
       4,    0,   71,    2, 0x08,    3 /* Private */,
       5,    0,   72,    2, 0x08,    4 /* Private */,
       6,    0,   73,    2, 0x08,    5 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    0,   77,    2, 0x08,    9 /* Private */,
      11,    0,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'paintEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>,
        // method 'przesuniecieX_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'przesuniecieY_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'przesuniecieZ_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotacjaX_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotacjaY_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotacjaZ_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'skala_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Reset_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        case 1: _t->przesuniecieX_slot(); break;
        case 2: _t->przesuniecieY_slot(); break;
        case 3: _t->przesuniecieZ_slot(); break;
        case 4: _t->rotacjaX_slot(); break;
        case 5: _t->rotacjaY_slot(); break;
        case 6: _t->rotacjaZ_slot(); break;
        case 7: _t->skala_slot(); break;
        case 8: _t->Reset_slot(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
