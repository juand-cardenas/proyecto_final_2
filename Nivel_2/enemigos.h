#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsItem>
#include<Qpainter>
#include<QGraphicsPixmapItem>
#include<QPixmap>

class Enemigos: public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    //Atributos
    int pos_x,pos_y,radio,largo=162,ancho=125,velocidad=12;
    QPixmap *mapa_sprite_en=new QPixmap(":/Enemigo/sprites/Enemigos/enemigo_derecha2.png");

public:
    //METODOS
    //CONSTRUCTORES
    Enemigos();
    Enemigos(int x,int y);
    //DECLARACIONES DE FUNCIONES QUE ERAN ABSTRACTAS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //GETTERS

    //DESTRUCTORES
    ~Enemigos();
};

#endif // ENEMIGOS_H
