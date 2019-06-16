/****************************************************************************
** Meta object code from reading C++ file 'guiscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "guiscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUIScreen_t {
    QByteArrayData data[16];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIScreen_t qt_meta_stringdata_GUIScreen = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GUIScreen"
QT_MOC_LITERAL(1, 10, 8), // "initName"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "initGame"
QT_MOC_LITERAL(4, 29, 15), // "exitMinesWeeper"
QT_MOC_LITERAL(5, 45, 10), // "launchGame"
QT_MOC_LITERAL(6, 56, 6), // "height"
QT_MOC_LITERAL(7, 63, 5), // "width"
QT_MOC_LITERAL(8, 69, 7), // "nbBombs"
QT_MOC_LITERAL(9, 77, 17), // "launchDefaultGame"
QT_MOC_LITERAL(10, 95, 8), // "useBonus"
QT_MOC_LITERAL(11, 104, 10), // "printScore"
QT_MOC_LITERAL(12, 115, 8), // "showTime"
QT_MOC_LITERAL(13, 124, 15), // "mousePressEvent"
QT_MOC_LITERAL(14, 140, 12), // "QMouseEvent*"
QT_MOC_LITERAL(15, 153, 5) // "event"

    },
    "GUIScreen\0initName\0\0initGame\0"
    "exitMinesWeeper\0launchGame\0height\0"
    "width\0nbBombs\0launchDefaultGame\0"
    "useBonus\0printScore\0showTime\0"
    "mousePressEvent\0QMouseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    3,   62,    2, 0x08 /* Private */,
       9,    0,   69,    2, 0x08 /* Private */,
      10,    0,   70,    2, 0x08 /* Private */,
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void GUIScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUIScreen *_t = static_cast<GUIScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initName(); break;
        case 1: _t->initGame(); break;
        case 2: _t->exitMinesWeeper(); break;
        case 3: _t->launchGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 4: _t->launchDefaultGame(); break;
        case 5: _t->useBonus(); break;
        case 6: _t->printScore(); break;
        case 7: _t->showTime(); break;
        case 8: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GUIScreen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GUIScreen.data,
      qt_meta_data_GUIScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUIScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUIScreen.stringdata0))
        return static_cast<void*>(const_cast< GUIScreen*>(this));
    return QWidget::qt_metacast(_clname);
}

int GUIScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
