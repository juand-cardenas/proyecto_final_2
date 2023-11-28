#include "personaje_nivel_1.h"

personaje_nivel1::personaje_nivel1()
{

}

personaje_nivel1::personaje_nivel1(int x,int y)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
}

personaje_nivel1::~personaje_nivel1()
{
    delete mapa_personaje;
}

QRectF personaje_nivel1::boundingRect() const
{
    return QRectF(-ancho/2,-altura/2,ancho,altura);
}

void personaje_nivel1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);


    painter->drawPixmap(boundingRect(),*mapa_personaje,mapa_personaje->rect());
}

void personaje_nivel1::movimiento_derecha()
{
    mapa_personaje->load("Derecha.png");
    pos_x+=velocidad;
    setPos(pos_x,pos_y);
}

void personaje_nivel1::movimiento_izquierda()
{
    mapa_personaje->load("Izquierda.png");
    pos_x-=velocidad;
    setPos(pos_x,pos_y);
}

void personaje_nivel1::movimiento_arriba()
{
    mapa_personaje->load("espalda.png");
    pos_y=pos_y-10*velocidad;
    pos_x=338;
    setPos(pos_x,pos_y);
}


int personaje_nivel1::getPos_x() const
{
    return pos_x;
}

int personaje_nivel1::getPos_y() const
{
    return pos_y;
}

void personaje_nivel1 :: reinicio_posicion(int x, int y){
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
}
