#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QTime>
#include"personaje.h"
#include"enemigos.h"
#include "proyectil_personaje.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //METODOS
    void keyPressEvent(QKeyEvent *e);
    void mover_enemigo_colisionado(int key);
    void mover_enemigo_colisionado_personaje(int key);
    void Nivel_2_terminado(bool win_lose);


    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene2;
    QGraphicsLineItem *l1,*l2;
    QMap<int,Enemigos *> Mapa_enemigos;

    QVector<Proyectil_personaje*> vector_proyectiles;
    QVector<QGraphicsPixmapItem*> corazones;
    QPixmap *cora=new QPixmap("C:/Users/User/Pictures/heart pixel art/heart pixel art 32x32.png");
    QMessageBox *msgbox=new QMessageBox();

    Personaje *p1,*p2;
    QTime cuenta_regresiva;
    QTimer *timer_cronometro, *timer_mov_colisiones_aparicion;
private slots:
    void mov_enemigos();
    void colision_entre_enemigos();
    void colision_enemigo_personaje();
    void colision_enemigo_proyectil();
    void aparicion_periodica_enemigos();
    void fin_dejuego();




};
#endif // MAINWINDOW_H
