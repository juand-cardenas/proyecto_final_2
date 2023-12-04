/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Nivel_1/mainwindow.h"
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
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[363];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 7), // "escena1"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 22), // "crear_grupo_de_bolitas"
QT_MOC_LITERAL(4, 43, 12), // "linea_limite"
QT_MOC_LITERAL(5, 56, 12), // "inicio_juego"
QT_MOC_LITERAL(6, 69, 21), // "actualizar_cronometro"
QT_MOC_LITERAL(7, 91, 17), // "actualizar_estado"
QT_MOC_LITERAL(8, 109, 18), // "movimiento_bolitas"
QT_MOC_LITERAL(9, 128, 19), // "actualizar_enemigos"
QT_MOC_LITERAL(10, 148, 8), // "colicion"
QT_MOC_LITERAL(11, 157, 22), // "definir_final_de_juego"
QT_MOC_LITERAL(12, 180, 20), // "movimiento_bolitas_2"
QT_MOC_LITERAL(13, 201, 29), // "tipo_movimiento_del_obstaculo"
QT_MOC_LITERAL(14, 231, 12), // "mov_enemigos"
QT_MOC_LITERAL(15, 244, 23), // "colision_entre_enemigos"
QT_MOC_LITERAL(16, 268, 26), // "colision_enemigo_personaje"
QT_MOC_LITERAL(17, 295, 26), // "colision_enemigo_proyectil"
QT_MOC_LITERAL(18, 322, 28), // "aparicion_periodica_enemigos"
QT_MOC_LITERAL(19, 351, 11) // "fin_dejuego"

    },
    "MainWindow\0escena1\0\0crear_grupo_de_bolitas\0"
    "linea_limite\0inicio_juego\0"
    "actualizar_cronometro\0actualizar_estado\0"
    "movimiento_bolitas\0actualizar_enemigos\0"
    "colicion\0definir_final_de_juego\0"
    "movimiento_bolitas_2\0tipo_movimiento_del_obstaculo\0"
    "mov_enemigos\0colision_entre_enemigos\0"
    "colision_enemigo_personaje\0"
    "colision_enemigo_proyectil\0"
    "aparicion_periodica_enemigos\0fin_dejuego"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->escena1(); break;
        case 1: _t->crear_grupo_de_bolitas(); break;
        case 2: _t->linea_limite(); break;
        case 3: _t->inicio_juego(); break;
        case 4: _t->actualizar_cronometro(); break;
        case 5: _t->actualizar_estado(); break;
        case 6: _t->movimiento_bolitas(); break;
        case 7: _t->actualizar_enemigos(); break;
        case 8: _t->colicion(); break;
        case 9: _t->definir_final_de_juego(); break;
        case 10: _t->movimiento_bolitas_2(); break;
        case 11: _t->tipo_movimiento_del_obstaculo(); break;
        case 12: _t->mov_enemigos(); break;
        case 13: _t->colision_entre_enemigos(); break;
        case 14: _t->colision_enemigo_personaje(); break;
        case 15: _t->colision_enemigo_proyectil(); break;
        case 16: _t->aparicion_periodica_enemigos(); break;
        case 17: _t->fin_dejuego(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
