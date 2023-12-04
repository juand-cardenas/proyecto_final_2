#include "personaje.h"



Personaje::Personaje()
{

}

Personaje::Personaje(int x, int y)
{
    pos_x=x;
    pos_y=y;

    setPos(pos_x,pos_y);

}



QRectF Personaje::boundingRect() const
{

    return QRectF(-ancho/2,-largo/2,ancho,largo);
}


void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);


    painter->drawPixmap(boundingRect(),*mapa_sprite,mapa_sprite->rect());
}
void Personaje::setVida(int newVida)
{
    vida = newVida;
}
//MOVIMIENTOS
void Personaje::Mov_up()
{
    mapa_sprite->load(":/Morty/sprites/Morty/MortyDetras1.png");
    pos_y-=velocidad;
    setPos(pos_x,pos_y);

}

void Personaje::Mov_down()
{
    mapa_sprite->load(":/Morty/sprites/Morty/MortyFrente1.png");
    pos_y+=velocidad;
    setPos(pos_x,pos_y);
}

void Personaje::Mov_left()
{
    mapa_sprite->load(":/Morty/sprites/Morty/MortyIzquierda1.png");
    pos_x-=velocidad;
    setPos(pos_x,pos_y);
}

void Personaje::Mov_rigth()
{
    mapa_sprite->load(":/Morty/sprites/Morty/MortyDerecha1.png");
    pos_x+=velocidad;
    setPos(pos_x,pos_y);
}

QPixmap *Personaje::get_mapa_sprite()
{
    return mapa_sprite;
}

int Personaje::get_pos_x()
{
    return pos_x;
}

int Personaje::get_pos_y()
{
    return pos_y;
}


int Personaje::getVida()
{
    return vida;
}

Personaje::~Personaje()
{
    delete mapa_sprite;
}


