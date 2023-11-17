#include "proyectil_personaje.h"

Proyectil_personaje::Proyectil_personaje()
{

}

QRectF Proyectil_personaje::boundingRect() const
{
    return QRectF(0,0,ancho,largo);
}

void Proyectil_personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);

    painter->drawRect(boundingRect());
    //painter->drawPixmap(boundingRect(),*mapa_proyec_per,mapa_proyec_per->rect());
}

Proyectil_personaje::~Proyectil_personaje()
{
    delete [] mapa_proyec_per;
}
