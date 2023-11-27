#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMap>
#include <QPixmap>
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
    void mov_colision_enemigo(int key);


    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene2;
    QGraphicsLineItem *l1,*l2;
    QGraphicsPixmapItem *personaje;
    QPixmap pm;
    QMap<int,Enemigos *> Mapa_enemigos;
    Enemigos *enemigo,*enemigo2;
    Personaje *p1,*p2;
    Proyectil_personaje *bullet;
    QTimer *timer_mov,*timer_colision;
private slots:
    void mov_enemigos();
    void colision_enemigos();

};
#endif // MAINWINDOW_H
