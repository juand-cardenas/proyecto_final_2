#include "proyectil_personaje.h"
#include <QDebug>

Proyectil_personaje::Proyectil_personaje()
{

}

Proyectil_personaje::Proyectil_personaje(int x, int y,char direccion)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
    if(direccion=='l'){
        qDebug()<<"izquierda";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_left()));
    }
    else if(direccion=='r'){
        qDebug()<<"derecha";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_rigth()));
    }
    else if(direccion=='u'){
        qDebug()<<"Arriba";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_up()));
    }
    else if(direccion=='d'){
        qDebug()<<"Abajo";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_down()));
    }
    timer->start(15);

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
    delete  mapa_proyec_per;
}
