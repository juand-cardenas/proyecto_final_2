#ifndef BOLITA_H
#define BOLITA_H

#include <QObject>
#include<QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <time.h>

class bolita:public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
private:
    //ATRIBUTOS
    double pos_x,pos_y,radio=15,movi_y,movi_x,vel_y;
    double angulo=0;
public:
    bolita();
    bolita(double x,double y);
    //METODOS
    //ABSTRACTOS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //SETTERS
    void setPos_x(double newPos_x);
    void setPos_y(double newPos_y);
    void setMovi_y(double newMovi_y);
    void setMovi_x(double newMovi_x);
    void setVel_y(double newVel_y);
    void colocar_posiciones(double x, double y);
    //GETTERS
    double getPos_x() ;
    double getPos_y() ;
    double getMovi_y();
    double getMovi_x();
    double getVel_y() ;
    void setAngulo(double newAngulo);
    double getAngulo() const;
    double getRadio() const;
};

#endif // BOLITA_H
