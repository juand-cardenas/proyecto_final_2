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
    QTimer *timer_1=new QTimer();
    QTimer *timer_2=new QTimer();
    QTimer *timer_3=new QTimer();
    QTime timed;
    QMessageBox msgbox;
    void keyPressEvent(QKeyEvent *e);
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


private:
    //METODOS PRIVADOS

//-------------------------------------------------------------------------
    Ui::MainWindow *ui;
    QGraphicsScene *scene1=new QGraphicsScene;
    personaje_nivel1 * personaje=new personaje_nivel1(338,537);
    bolita *bolitam=new bolita(200,6);
    bolita auxiliar;
    QGraphicsLineItem *l1;
    vector<bolita *>bolitas={};// crear vector de bolitas
    bool estado_escena;
    int cant_enemigos;
};
#endif // MAINWINDOW_H
