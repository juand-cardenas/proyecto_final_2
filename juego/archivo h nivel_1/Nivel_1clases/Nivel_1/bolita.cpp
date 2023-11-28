#include "bolita.h"



bolita::bolita()
{

}

bolita::bolita(double x, double y)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
}

QRectF bolita::boundingRect() const
{
    return QRectF(-radio,-radio,1.3*radio,1.3*radio);

}

void bolita::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen line(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter->setPen(line);
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}
//SETTERS
void bolita::setPos_x(double newPos_x)
{
    pos_x = newPos_x;
}

void bolita::setPos_y(double newPos_y)
{
    pos_y = newPos_y;
}

void bolita::setMovi_y(double newMovi_y)
{
    movi_y = newMovi_y;
}

void bolita::setMovi_x(double newMovi_x)
{
    movi_x = newMovi_x;
}

void bolita::setVel_y(double newVel_y)
{
    vel_y = newVel_y;
}

void bolita::colocar_posiciones(double x,double y)
{
    pos_x=x;
    pos_y=y;
    setPos(pos_x,pos_y);
}
//GETTERS
double bolita::getPos_x()
{
    return pos_x;
}

double bolita::getPos_y()
{
    return pos_y;
}

double bolita::getMovi_y()
{
    return movi_y;
}

double bolita::getMovi_x()
{
    return movi_x;
}

double bolita::getVel_y()
{
    return vel_y;
}



