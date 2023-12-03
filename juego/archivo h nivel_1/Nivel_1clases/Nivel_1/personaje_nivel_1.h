#ifndef PERSONAJE_NIVEL1_H
#define PERSONAJE_NIVEL1_H

#include<QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QPixmap>

class personaje_nivel1:public QObject,public QGraphicsItem
{
    Q_OBJECT
private:
    //ATRIBUTOS:
    int pos_x,pos_y,velocidad=6,ancho=121,altura=143;
    QPixmap *mapa_personaje=new QPixmap(":/imagenes_juego/espalda.png");
public:
    personaje_nivel1();
    personaje_nivel1(int x,int y);
    QTime timed;
    ~personaje_nivel1();

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //METODOS
    void movimiento_derecha();
    void movimiento_izquierda();
    void movimiento_arriba();
    void reinicio_posicion(int x, int y);
    int getPos_x() const;

    int getPos_y() const;
};


#endif // PERSONAJE_NIVEL1_H
