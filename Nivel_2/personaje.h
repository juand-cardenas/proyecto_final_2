#ifndef PERSONAJE_H
#define PERSONAJE_H
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsPixmapItem>
#include<QPixmap>
#include <QKeyEvent>

class Personaje: public QGraphicsItem
{

private:
    //atributos:
    int pos_x,pos_y,radio,largo=162,ancho=125,velocidad=12,vida=100;
    QPixmap *mapa_sprite=new QPixmap(":/Morty/sprites/Morty/MortyDerecha1.png");

public:

    //METODOS
    //CONSTRUCTORES
    Personaje();
    Personaje(int x,int y);
    //DECLARACION DE METODOS QUE ERAN ABSTRACTOS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //MOVIMIENTOS;
    void Mov_up();
    void Mov_down();
    void Mov_left();
    void Mov_rigth();
    //GETTERS
    QPixmap *get_mapa_sprite();
    int get_pos_x();
    int get_pos_y();
    //DSETRUCTOR
    ~Personaje();

};

#endif // PERSONAJE_H
