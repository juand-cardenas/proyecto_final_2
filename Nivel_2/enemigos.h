#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QObject>
#include <QGraphicsItem>

class Enemigos: public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    //Atributos

    Enemigos();
};

#endif // ENEMIGOS_H
