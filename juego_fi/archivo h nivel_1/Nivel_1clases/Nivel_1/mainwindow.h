#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMap>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include<QVector>
#include <vector>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include "personaje_nivel_1.h"
#include "bolita.h"
#include"personaje.h"
#include"enemigos.h"
#include "proyectil_personaje.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//atributo, entre otras cosas----------------------
    bool nivel_actual=true;
    QTimer *timer_1=new QTimer();
    QTimer *timer_2=new QTimer();
    QTimer *timer_3=new QTimer();
    QTime timed;
    QMessageBox msgbox;
    //METODOS
    void keyPressEvent(QKeyEvent *e);
    //METODOS NIVEL_2
    void mover_enemigo_colisionado(int key);
    void mover_enemigo_colisionado_personaje(int key);
    void Nivel_2_terminado(bool win_lose);
    void Inicio_Nivel_2();
private slots:
    //METODOS PRIVADOS

    void escena1();
    void crear_grupo_de_bolitas();
    void linea_limite();
    void inicio_juego();
    void actualizar_cronometro();
    void actualizar_estado();
    void movimiento_bolitas();
    void actualizar_enemigos();
    void colicion();
    void definir_final_de_juego();
    void movimiento_bolitas_2();
    void tipo_movimiento_del_obstaculo();
    //METODOS/SLOTS NIVEL 2
    void mov_enemigos();
    void colision_entre_enemigos();
    void colision_enemigo_personaje();
    void colision_enemigo_proyectil();
    void aparicion_periodica_enemigos();
    void fin_dejuego();

private:
    //METODOS PRIVADOS

//-------------------------------------------------------------------------
    Ui::MainWindow *ui;
    QGraphicsScene *scene1=new QGraphicsScene;
    personaje_nivel1 * personaje=new personaje_nivel1(338,537);
    bolita auxiliar;
    QGraphicsLineItem *l1;
    vector<bolita *>bolitas={};// crear vector de bolitas
    bool estado_escena;
    int tipo_de_movimiento;
    int cant_enemigos;
    //ATRIBUTOS NIVEL_2
    QGraphicsScene *scene2;
    QMap<int,Enemigos *> Mapa_enemigos;
    QVector<Proyectil_personaje*> vector_proyectiles;
    QVector<QGraphicsPixmapItem*> corazones;
    QPixmap *cora=new QPixmap(":/Vida/sprites/Vida/heart pixel art 32x32.png");
    QMessageBox *Msgbox=new QMessageBox();

    Personaje *p1,*p2;
    QTime cuenta_regresiva;
    QTimer *timer_cronometro_2, *timer_mov_colisiones_aparicion;
};
#endif // MAINWINDOW_H
