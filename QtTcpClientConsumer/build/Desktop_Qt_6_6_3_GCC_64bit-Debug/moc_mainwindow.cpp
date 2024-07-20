/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "getData",
    "",
    "tcpConnect",
    "tcpDisconnect",
    "updateIp",
    "startButton",
    "stopTimer",
    "intervalTimer",
    "interval",
    "timerEvent"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[14];
    char stringdata5[9];
    char stringdata6[12];
    char stringdata7[10];
    char stringdata8[14];
    char stringdata9[9];
    char stringdata10[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 7),  // "getData"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 10),  // "tcpConnect"
        QT_MOC_LITERAL(31, 13),  // "tcpDisconnect"
        QT_MOC_LITERAL(45, 8),  // "updateIp"
        QT_MOC_LITERAL(54, 11),  // "startButton"
        QT_MOC_LITERAL(66, 9),  // "stopTimer"
        QT_MOC_LITERAL(76, 13),  // "intervalTimer"
        QT_MOC_LITERAL(90, 8),  // "interval"
        QT_MOC_LITERAL(99, 10)   // "timerEvent"
    },
    "MainWindow",
    "getData",
    "",
    "tcpConnect",
    "tcpDisconnect",
    "updateIp",
    "startButton",
    "stopTimer",
    "intervalTimer",
    "interval",
    "timerEvent"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x0a,    2 /* Public */,
       4,    0,   64,    2, 0x0a,    3 /* Public */,
       5,    0,   65,    2, 0x0a,    4 /* Public */,
       6,    0,   66,    2, 0x0a,    5 /* Public */,
       7,    0,   67,    2, 0x0a,    6 /* Public */,
       8,    1,   68,    2, 0x0a,    7 /* Public */,
      10,    0,   71,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'getData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tcpConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tcpDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateIp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'intervalTimer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'timerEvent'
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
        case 0: _t->getData(); break;
        case 1: _t->tcpConnect(); break;
        case 2: _t->tcpDisconnect(); break;
        case 3: _t->updateIp(); break;
        case 4: _t->startButton(); break;
        case 5: _t->stopTimer(); break;
        case 6: _t->intervalTimer((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->timerEvent(); break;
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
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
