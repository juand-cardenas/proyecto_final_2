#ifndef PROYECTIL_PERSONAJE_H
#define PROYECTIL_PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include<Qpainter>
#include<QGraphicsPixmapItem>
#include<QTimer>

class Proyectil_personaje:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    //ATRIBUTOS
    int pos_x,pos_y,ancho=40,largo=31, velocidad=8;
    QPixmap *mapa_proyec_per=new QPixmap(":/Enemigo/sprites/Enemigos/enemigo_derecha2.png");
    QTimer *timer=new QTimer();
public:
    //METODOS
    //CONSTRUCTOR
    Proyectil_personaje();
    Proyectil_personaje(int x,int y);
    //DECLARACIONES DE FUNCIONES QUE ERAN ABSTRACTAS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //MOVIMIENTO BALA

    void Mov_up();
    void Mov_down();
    void Mov_left();
    void Mov_rigth();

    //DESTRUCTOR
    ~Proyectil_personaje();
};

#endif // PROYECTIL_PERSONAJE_H
