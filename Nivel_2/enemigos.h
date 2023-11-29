#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsItem>
#include<Qpainter>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include<QTimer>
#include"personaje.h"


class Enemigos: public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:
    //Atributos
    int pos_x,pos_y,largo=64,ancho=64,velocidad=15;
    QPixmap *mapa_sprite_en=new QPixmap(":/Enemigo/sprites/Enemigos/copy.png");


public:
    //METODOS
    //CONSTRUCTORES
    Enemigos();
    Enemigos(int x,int y);
    //DECLARACIONES DE FUNCIONES QUE ERAN ABSTRACTAS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //MOVIMIENTOS
    void Move_up();
    void Move_down();
    void Move_left();
    void Move_rigth();
    //SETTERS
    void set_posiciones(int x,int y);
    //GETTERS
    int get_pos_y();
    int get_pos_x();
    int get_velocidad();
    void persecucion_personaje(int personaje_x,int personaje_y);
    //DESTRUCTORES
    ~Enemigos();
};

#endif // ENEMIGOS_H
