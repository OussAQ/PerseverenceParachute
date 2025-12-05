/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HistoryWindow_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistoryWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistoryWindow_t qt_meta_stringdata_HistoryWindow = {
    {
QT_MOC_LITERAL(0, 0, 13) // "HistoryWindow"

    },
    "HistoryWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoryWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void HistoryWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject HistoryWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HistoryWindow.data,
    qt_meta_data_HistoryWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HistoryWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoryWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HistoryWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[24];
    char stringdata0[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "onMessageChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "text"
QT_MOC_LITERAL(4, 34, 22), // "onReferenceCharChanged"
QT_MOC_LITERAL(5, 57, 23), // "onSectorsSpinBoxChanged"
QT_MOC_LITERAL(6, 81, 5), // "value"
QT_MOC_LITERAL(7, 87, 22), // "onSectorsSliderChanged"
QT_MOC_LITERAL(8, 110, 22), // "onTracksSpinBoxChanged"
QT_MOC_LITERAL(9, 133, 21), // "onTracksSliderChanged"
QT_MOC_LITERAL(10, 155, 20), // "generateRandomColors"
QT_MOC_LITERAL(11, 176, 11), // "resetColors"
QT_MOC_LITERAL(12, 188, 7), // "newFile"
QT_MOC_LITERAL(13, 196, 8), // "openFile"
QT_MOC_LITERAL(14, 205, 8), // "saveFile"
QT_MOC_LITERAL(15, 214, 10), // "saveFileAs"
QT_MOC_LITERAL(16, 225, 8), // "copyText"
QT_MOC_LITERAL(17, 234, 9), // "pasteText"
QT_MOC_LITERAL(18, 244, 8), // "clearAll"
QT_MOC_LITERAL(19, 253, 19), // "toggleHistoryWindow"
QT_MOC_LITERAL(20, 273, 7), // "checked"
QT_MOC_LITERAL(21, 281, 16), // "toggleBinaryView"
QT_MOC_LITERAL(22, 298, 9), // "showAbout"
QT_MOC_LITERAL(23, 308, 8) // "showHelp"

    },
    "MainWindow\0onMessageChanged\0\0text\0"
    "onReferenceCharChanged\0onSectorsSpinBoxChanged\0"
    "value\0onSectorsSliderChanged\0"
    "onTracksSpinBoxChanged\0onTracksSliderChanged\0"
    "generateRandomColors\0resetColors\0"
    "newFile\0openFile\0saveFile\0saveFileAs\0"
    "copyText\0pasteText\0clearAll\0"
    "toggleHistoryWindow\0checked\0"
    "toggleBinaryView\0showAbout\0showHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x08 /* Private */,
       4,    0,  112,    2, 0x08 /* Private */,
       5,    1,  113,    2, 0x08 /* Private */,
       7,    1,  116,    2, 0x08 /* Private */,
       8,    1,  119,    2, 0x08 /* Private */,
       9,    1,  122,    2, 0x08 /* Private */,
      10,    0,  125,    2, 0x08 /* Private */,
      11,    0,  126,    2, 0x08 /* Private */,
      12,    0,  127,    2, 0x08 /* Private */,
      13,    0,  128,    2, 0x08 /* Private */,
      14,    0,  129,    2, 0x08 /* Private */,
      15,    0,  130,    2, 0x08 /* Private */,
      16,    0,  131,    2, 0x08 /* Private */,
      17,    0,  132,    2, 0x08 /* Private */,
      18,    0,  133,    2, 0x08 /* Private */,
      19,    1,  134,    2, 0x08 /* Private */,
      21,    1,  137,    2, 0x08 /* Private */,
      22,    0,  140,    2, 0x08 /* Private */,
      23,    0,  141,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMessageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onReferenceCharChanged(); break;
        case 2: _t->onSectorsSpinBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onSectorsSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onTracksSpinBoxChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onTracksSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->generateRandomColors(); break;
        case 7: _t->resetColors(); break;
        case 8: _t->newFile(); break;
        case 9: _t->openFile(); break;
        case 10: _t->saveFile(); break;
        case 11: _t->saveFileAs(); break;
        case 12: _t->copyText(); break;
        case 13: _t->pasteText(); break;
        case 14: _t->clearAll(); break;
        case 15: _t->toggleHistoryWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->toggleBinaryView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->showAbout(); break;
        case 18: _t->showHelp(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
