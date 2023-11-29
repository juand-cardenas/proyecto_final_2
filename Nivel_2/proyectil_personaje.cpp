



#include "proyectil_personaje.h"
#include <QDebug>

QTimer *Proyectil_personaje::getTimer() const
{
    return timer;
}

Proyectil_personaje::Proyectil_personaje()
{

}

Proyectil_personaje::Proyectil_personaje(int x, int y,char direccion)
{
    pos_x=x;
    pos_y=y;
    y_final=y;
    direccion_disparo=direccion;
    setPos(pos_x,pos_y);
    if(direccion_disparo=='l'){
        qDebug()<<"izquierda";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_left()));
    }
    else if(direccion_disparo=='r'){
        qDebug()<<"derecha";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_rigth()));
    }
    else if(direccion_disparo=='u'){
        qDebug()<<"Arriba";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_up()));
    }
    else if(direccion_disparo=='d'){
        qDebug()<<"Abajo";
        connect(timer,SIGNAL(timeout()),this,SLOT(Mov_down()));
    }




}

QRectF Proyectil_personaje::boundingRect() const
{
    return QRectF(-ancho/2,-largo/2,ancho,largo);
}

void Proyectil_personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);

    //painter->drawRect(boundingRect());
    painter->drawPixmap(boundingRect(),*mapa_proyec_per,mapa_proyec_per->rect());
}

void Proyectil_personaje::set_posiciones(double x, double y)
{
    pos_x=x;
    pos_y=y;
    y_final=y;
    velocidad_x=35;
    velocidad_y=28;
    setPos(pos_x,pos_y);



}

void Proyectil_personaje::Mov_up()
{
    if(pos_y>-ancho/2){
        pos_y-=velocidad_x;
        setPos(pos_x,pos_y);

    }
    else{
        timer->stop();
    }
}

void Proyectil_personaje::Mov_down()
{
    if(pos_y<600+ancho/2){
        pos_y+=velocidad_x;
        setPos(pos_x,pos_y);
    }
    else{
        timer->stop();
    }
}

void Proyectil_personaje::Mov_left()
{

    //qDebug()<<"pos_x:"<<pos_x;
    //qDebug()<<"pos_y:"<<pos_y;
    //qDebug()<<"El Y_final es:"<<y_final;
    if(pos_y<=y_final){

        pos_x=pos_x-velocidad_x*tiempo;
        pos_y=pos_y-velocidad_y*tiempo+0.5*9.8*tiempo*tiempo;
        velocidad_y-=+9.8*tiempo;
        //qDebug()<<y_final;
        //qDebug()<<pos_y;
        setPos(pos_x,pos_y);

    }
    else{
        timer->stop();
        set_posiciones(700,-100);
    }



}

void Proyectil_personaje::Mov_rigth()
{
    if(pos_y<=y_final){

        pos_x=pos_x+velocidad_x*tiempo;
        pos_y=pos_y-velocidad_y*tiempo+0.5*9.8*tiempo*tiempo;
        velocidad_y-=+9.8*tiempo;
        //qDebug()<<y_final;
        //qDebug()<<pos_y;
        setPos(pos_x,pos_y);

    }
    else{
        timer->stop();
        set_posiciones(700,-200);
    }
}

Proyectil_personaje::~Proyectil_personaje()
{
    delete  mapa_proyec_per;
}
