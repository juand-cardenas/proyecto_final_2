#include "proyectil_personaje.h"

Proyectil_personaje::Proyectil_personaje()
{

}

Proyectil_personaje::Proyectil_personaje(int x, int y)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mov_up()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Mov_down()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Mov_left()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Mov_rigth()));
    timer->start(500);
}

QRectF Proyectil_personaje::boundingRect() const
{
    return QRectF(0,0,ancho,largo);
}

void Proyectil_personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);

    painter->drawRect(boundingRect());
    //painter->drawPixmap(boundingRect(),*mapa_proyec_per,mapa_proyec_per->rect());
}

void Proyectil_personaje::Mov_up()
{
    pos_y-=velocidad;
    setPos(pos_x,pos_y);
}

void Proyectil_personaje::Mov_down()
{
    pos_y+=velocidad;
    setPos(pos_x,pos_y);
}

void Proyectil_personaje::Mov_left()
{
    pos_x-=velocidad;
    setPos(pos_x,pos_y);
}

void Proyectil_personaje::Mov_rigth()
{
    pos_x+=velocidad;
    setPos(pos_x,pos_y);
}

Proyectil_personaje::~Proyectil_personaje()
{
    delete [] mapa_proyec_per;
}
