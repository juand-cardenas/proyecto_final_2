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
    return QRectF(0,0,ancho,largo);
}

void Enemigos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);


    painter->drawPixmap(boundingRect(),*mapa_sprite_en,mapa_sprite_en->rect());
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
    int _x=x(),_y=y();
    int dy=y()-personaje_y,dx=x()-personaje_x;
    if(dx>0){
        _x-=velocidad;
    }
    else if(dx<0){
        _x+=velocidad;
    }
    if(dy>0){
        _y-=velocidad;
    }
    else if(dy<0){
        _y+=velocidad;

    }
    setPos(_x,_y);

}

Enemigos::~Enemigos()
{
    delete mapa_sprite_en;
}
