/****************************************************************************
** Meta object code from reading C++ file 'spellbook.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../spellbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spellbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Spellbook[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x08,
      56,   51,   10,   10, 0x08,
      97,   51,   10,   10, 0x08,
     149,  138,   10,   10, 0x08,
     185,  138,   10,   10, 0x08,
     219,   11,   10,   10, 0x08,
     257,   11,   10,   10, 0x08,
     291,   11,   10,   10, 0x08,
     379,  327,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Spellbook[] = {
    "Spellbook\0\0index\0on_spellList_clicked(QModelIndex)\0"
    "arg1\0on_sort1Box_currentIndexChanged(QString)\0"
    "on_sort2Box_currentIndexChanged(QString)\0"
    "row,column\0on_spellList_cellActivated(int,int)\0"
    "on_spellList_cellEntered(int,int)\0"
    "on_filterBox_currentIndexChanged(int)\0"
    "on_spellList_entered(QModelIndex)\0"
    "on_spellList_activated(QModelIndex)\0"
    "currentRow,currentColumn,previousRow,previousColumn\0"
    "on_spellList_currentCellChanged(int,int,int,int)\0"
};

void Spellbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Spellbook *_t = static_cast<Spellbook *>(_o);
        switch (_id) {
        case 0: _t->on_spellList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_sort1Box_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_sort2Box_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_spellList_cellActivated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_spellList_cellEntered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_filterBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_spellList_entered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_spellList_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_spellList_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Spellbook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Spellbook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Spellbook,
      qt_meta_data_Spellbook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Spellbook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Spellbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Spellbook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Spellbook))
        return static_cast<void*>(const_cast< Spellbook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Spellbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
