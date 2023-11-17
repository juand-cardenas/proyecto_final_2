#ifndef PROYECTIL_PERSONAJE_H
#define PROYECTIL_PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include<Qpainter>
#include<QGraphicsPixmapItem>

class Proyectil_personaje:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    //ATRIBUTOS
    int pos_x,pos_y,ancho=40,largo=31;
    QPixmap *mapa_proyec_per=new QPixmap(":/Enemigo/sprites/Enemigos/enemigo_derecha2.png");
public:
    //METODOS
    //CONSTRUCTOR
    Proyectil_personaje();
    //DECLARACIONES DE FUNCIONES QUE ERAN ABSTRACTAS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //DESTRUCTOR
    ~Proyectil_personaje();
};

#endif // PROYECTIL_PERSONAJE_H
