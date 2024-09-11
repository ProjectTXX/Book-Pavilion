/****************************************************************************
** Meta object code from reading C++ file 'success.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../chht-dev/success.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'success.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Success_t {
    QByteArrayData data[17];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Success_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Success_t qt_meta_stringdata_Success = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Success"
QT_MOC_LITERAL(1, 8, 25), // "on_playinandpasue_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "setSliderValue"
QT_MOC_LITERAL(4, 50, 24), // "on_hprogress_sliderMoved"
QT_MOC_LITERAL(5, 75, 8), // "position"
QT_MOC_LITERAL(6, 84, 22), // "on_vVolume_sliderMoved"
QT_MOC_LITERAL(7, 107, 17), // "on_btnadd_clicked"
QT_MOC_LITERAL(8, 125, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(9, 157, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(10, 174, 4), // "item"
QT_MOC_LITERAL(11, 179, 17), // "on_btnPre_clicked"
QT_MOC_LITERAL(12, 197, 18), // "on_btnNext_clicked"
QT_MOC_LITERAL(13, 216, 11), // "getduration"
QT_MOC_LITERAL(14, 228, 11), // "setPlayTime"
QT_MOC_LITERAL(15, 240, 20), // "on_btnvolume_clicked"
QT_MOC_LITERAL(16, 261, 25) // "on_vVolume_sliderReleased"

    },
    "Success\0on_playinandpasue_clicked\0\0"
    "setSliderValue\0on_hprogress_sliderMoved\0"
    "position\0on_vVolume_sliderMoved\0"
    "on_btnadd_clicked\0on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_btnPre_clicked\0"
    "on_btnNext_clicked\0getduration\0"
    "setPlayTime\0on_btnvolume_clicked\0"
    "on_vVolume_sliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Success[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Success::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Success *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_playinandpasue_clicked(); break;
        case 1: _t->setSliderValue(); break;
        case 2: _t->on_hprogress_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_vVolume_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btnadd_clicked(); break;
        case 5: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->on_btnPre_clicked(); break;
        case 7: _t->on_btnNext_clicked(); break;
        case 8: _t->getduration(); break;
        case 9: _t->setPlayTime(); break;
        case 10: _t->on_btnvolume_clicked(); break;
        case 11: _t->on_vVolume_sliderReleased(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Success::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Success.data,
    qt_meta_data_Success,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Success::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Success::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Success.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Success::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
