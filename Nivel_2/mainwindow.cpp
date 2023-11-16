#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene2=new QGraphicsScene();
    scene2->setSceneRect(0,0,798,598);
    ui->graphicsView->setScene(scene2);

    QImage imagenFondo(":/Background/sprites/background/prueba.png");
    QBrush brochaFondo(imagenFondo);
    ui->graphicsView->setBackgroundBrush(brochaFondo);


    l1= scene2->addLine(0,220,0,600);//Y
   l2= scene2->addLine(0,220,700,220);//X
    pm.load(":/Morty/sprites/Morty/MortyDerecha1.png");
    personaje=new QGraphicsPixmapItem();
    p1=new Personaje (20,20);
    scene2->addItem(p1);


    scene2->addItem(personaje);
    //fig->setScale(0.5);
    personaje->setPixmap(pm);
    personaje->setPos(100,438);



}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_A && p1->getpos_x()>=0){

        p1->Mov_left();
    }
    else if(e->key()==Qt::Key_D && p1->getpos_x()<=673){
        p1->Mov_rigth();
    }
    else if(e->key()==Qt::Key_W && p1->getpos_y()>=220){

        p1->Mov_up();
    }
    else if(e->key()==Qt::Key_S && p1->getpos_y()<=436 ){

        p1->Mov_down();
    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

