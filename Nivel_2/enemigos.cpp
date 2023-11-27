#include "enemigos.h"

Enemigos::Enemigos()
{

}

Enemigos::Enemigos(int x, int y)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
}

QRectF Enemigos::boundingRect() const
{
    return QRectF(-ancho/2,-largo/2,ancho,largo);
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);


    painter->drawPixmap(boundingRect(),*mapa_sprite_en,mapa_sprite_en->rect());
}

void Enemigos::Move_up()
{
    pos_y-=4*velocidad;
    setPos(pos_x,pos_y);
}

void Enemigos::Move_down()
{
    pos_y+=4*velocidad;
    setPos(pos_x,pos_y);
}

void Enemigos::Move_left()
{
    pos_x-=4*velocidad;
    setPos(pos_x,pos_y);
}

void Enemigos::Move_rigth()
{
    pos_x+=4*velocidad;
    setPos(pos_x,pos_y);
}

int Enemigos::get_pos_y()
{
    return pos_y;
}

int Enemigos::get_pos_x()
{
    return pos_x;
}

int Enemigos::get_velocidad()
{
    return velocidad;
}

void Enemigos::persecucion_personaje(int personaje_x, int personaje_y)
{

    int dy=y()-personaje_y,dx=x()-personaje_x;
    if(dx>0){
        pos_x-=3*velocidad;
    }
    else if(dx<0){
        pos_x+=0.5*velocidad;
    }
    if(dy>0){
        pos_y-=3*velocidad;
    }
    else if(dy<0){
        pos_y+=0.5*velocidad;

    }
    setPos(pos_x,pos_y);

}

Enemigos::~Enemigos()
{
    delete mapa_sprite_en;
}
