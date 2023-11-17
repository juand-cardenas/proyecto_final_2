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

Enemigos::~Enemigos()
{
    delete[] mapa_sprite_en;
}
