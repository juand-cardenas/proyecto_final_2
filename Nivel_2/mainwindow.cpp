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


    p1=new Personaje (675,438);
    scene2->addItem(p1);
    e=new Enemigos(0,438);

    scene2->addItem(e);


}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_A && p1->get_pos_x()>=0){

        p1->Mov_left();
    }
    else if(e->key()==Qt::Key_D && p1->get_pos_x()<=673){
        p1->Mov_rigth();
    }
    else if(e->key()==Qt::Key_W && p1->get_pos_y()>=220){

        p1->Mov_up();
    }
    else if(e->key()==Qt::Key_S && p1->get_pos_y()<=436 ){

        p1->Mov_down();
    }
    else if(e->key()==Qt::Key_Space){

        bullet=new Proyectil_personaje(p1->get_pos_x(),p1->get_pos_y());
        QPixmap izquierda1(":/Morty/sprites/Morty/MortyIzquierda1.png");
        QPixmap derecha1(":/Morty/sprites/Morty/MortyIzquierda1.png");
        QPixmap frente1(":/Morty/sprites/Morty/MortyIzquierda1.png");
        QPixmap detras1(":/Morty/sprites/Morty/MortyIzquierda1.png");
        if(*p1->get_mapa_sprite()==izquierda1 ){
            //DISPARA A LA IZQUIERDA
           scene2->addItem(bullet);
        }
        else if(*p1->get_mapa_sprite()==derecha1){
             //DISPARA A LA DERECHA
        }
        else if(*p1->get_mapa_sprite()==frente1){
             //DISPARA  LA ABAJO
        }
        else if(*p1->get_mapa_sprite()==detras1){
             //DISPARA A ARRIBA
        }



    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

