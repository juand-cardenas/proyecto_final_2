#ifndef PROYECTIL_PERSONAJE_H
#define PROYECTIL_PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include<Qpainter>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<QList>
#include<math.h>

class Proyectil_personaje:public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

private:

    //ATRIBUTOS
    double pos_x,pos_y,ancho=32,largo=32, velocidad_x=35,velocidad_y=28,tiempo=1,y_final;
    char direccion_disparo;
    QPixmap *mapa_proyec_per=new QPixmap("C:/Users/User/Pictures/jWrNgV.png");
    QTimer *timer=new QTimer();


public:
    //METODOS
    //CONSTRUCTOR
    Proyectil_personaje();
    Proyectil_personaje(int x,int y,char direccion);
    //DECLARACIONES DE FUNCIONES QUE ERAN ABSTRACTAS
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    //MOVIMIENTO
    void set_posiciones(double x,double y);


    //DESTRUCTOR
    ~Proyectil_personaje();
    //MOVIMIENTO BALA
    QTimer *getTimer() const;

private slots:
    void Mov_up();
    void Mov_down();
    void Mov_left();
    void Mov_rigth();





};

#endif // PROYECTIL_PERSONAJE_H
