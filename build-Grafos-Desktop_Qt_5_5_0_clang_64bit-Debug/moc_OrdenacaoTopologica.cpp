/****************************************************************************
** Meta object code from reading C++ file 'OrdenacaoTopologica.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Grafos-master/OrdenacaoTopologica.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OrdenacaoTopologica.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OrdenacaoTopologica_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrdenacaoTopologica_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrdenacaoTopologica_t qt_meta_stringdata_OrdenacaoTopologica = {
    {
QT_MOC_LITERAL(0, 0, 19), // "OrdenacaoTopologica"
QT_MOC_LITERAL(1, 20, 6), // "update"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6) // "Graph*"

    },
    "OrdenacaoTopologica\0update\0\0Graph*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrdenacaoTopologica[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void OrdenacaoTopologica::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OrdenacaoTopologica *_t = static_cast<OrdenacaoTopologica *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< Graph*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Graph* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OrdenacaoTopologica::*_t)(Graph * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OrdenacaoTopologica::update)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OrdenacaoTopologica::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_OrdenacaoTopologica.data,
      qt_meta_data_OrdenacaoTopologica,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OrdenacaoTopologica::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrdenacaoTopologica::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OrdenacaoTopologica.stringdata0))
        return static_cast<void*>(const_cast< OrdenacaoTopologica*>(this));
    return QThread::qt_metacast(_clname);
}

int OrdenacaoTopologica::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void OrdenacaoTopologica::update(Graph * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
