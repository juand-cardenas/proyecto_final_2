/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Nivel_1/mainwindow.h"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "escena_1",
    "",
    "definir_final_de_juego",
    "actualizar_estado",
    "actualizar_cronometro",
    "posicion_personaje_inicio",
    "ESPALDA",
    "linea_limite",
    "obstaculo",
    "movimiento_obstaculo",
    "actualizar_enemigos",
    "colicion",
    "inicio_juego",
    "movimiento_2_obstaculo"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[18];
    char stringdata5[22];
    char stringdata6[26];
    char stringdata7[8];
    char stringdata8[13];
    char stringdata9[10];
    char stringdata10[21];
    char stringdata11[20];
    char stringdata12[9];
    char stringdata13[13];
    char stringdata14[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 8),  // "escena_1"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 22),  // "definir_final_de_juego"
        QT_MOC_LITERAL(44, 17),  // "actualizar_estado"
        QT_MOC_LITERAL(62, 21),  // "actualizar_cronometro"
        QT_MOC_LITERAL(84, 25),  // "posicion_personaje_inicio"
        QT_MOC_LITERAL(110, 7),  // "ESPALDA"
        QT_MOC_LITERAL(118, 12),  // "linea_limite"
        QT_MOC_LITERAL(131, 9),  // "obstaculo"
        QT_MOC_LITERAL(141, 20),  // "movimiento_obstaculo"
        QT_MOC_LITERAL(162, 19),  // "actualizar_enemigos"
        QT_MOC_LITERAL(182, 8),  // "colicion"
        QT_MOC_LITERAL(191, 12),  // "inicio_juego"
        QT_MOC_LITERAL(204, 22)   // "movimiento_2_obstaculo"
    },
    "MainWindow",
    "escena_1",
    "",
    "definir_final_de_juego",
    "actualizar_estado",
    "actualizar_cronometro",
    "posicion_personaje_inicio",
    "ESPALDA",
    "linea_limite",
    "obstaculo",
    "movimiento_obstaculo",
    "actualizar_enemigos",
    "colicion",
    "inicio_juego",
    "movimiento_2_obstaculo"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x08,    1 /* Private */,
       3,    0,   93,    2, 0x08,    2 /* Private */,
       4,    0,   94,    2, 0x08,    3 /* Private */,
       5,    0,   95,    2, 0x08,    4 /* Private */,
       6,    0,   96,    2, 0x08,    5 /* Private */,
       7,    0,   97,    2, 0x08,    6 /* Private */,
       8,    0,   98,    2, 0x08,    7 /* Private */,
       9,    0,   99,    2, 0x08,    8 /* Private */,
      10,    0,  100,    2, 0x08,    9 /* Private */,
      11,    0,  101,    2, 0x08,   10 /* Private */,
      12,    0,  102,    2, 0x08,   11 /* Private */,
      13,    0,  103,    2, 0x08,   12 /* Private */,
      14,    0,  104,    2, 0x08,   13 /* Private */,

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
        // method 'escena_1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'definir_final_de_juego'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizar_estado'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizar_cronometro'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'posicion_personaje_inicio'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ESPALDA'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'linea_limite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'obstaculo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimiento_obstaculo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'actualizar_enemigos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colicion'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'inicio_juego'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimiento_2_obstaculo'
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
        case 0: _t->escena_1(); break;
        case 1: _t->definir_final_de_juego(); break;
        case 2: _t->actualizar_estado(); break;
        case 3: _t->actualizar_cronometro(); break;
        case 4: _t->posicion_personaje_inicio(); break;
        case 5: _t->ESPALDA(); break;
        case 6: _t->linea_limite(); break;
        case 7: _t->obstaculo(); break;
        case 8: _t->movimiento_obstaculo(); break;
        case 9: _t->actualizar_enemigos(); break;
        case 10: _t->colicion(); break;
        case 11: _t->inicio_juego(); break;
        case 12: _t->movimiento_2_obstaculo(); break;
        default: ;
        }
    }
    (void)_a;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
