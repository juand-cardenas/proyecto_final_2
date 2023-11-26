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
    l2= scene2->addLine(0,260,700,260);//X


    p1=new Personaje (675,438);
    scene2->addItem(p1);
    for(int i=0;i<4;i++){
        if(i==0){
            Mapa_enemigos[i]=new Enemigos(10,260);
            scene2->addItem( Mapa_enemigos[i]);
        }
        else if(i==1){
            Mapa_enemigos[i]=new Enemigos(780,260);
            scene2->addItem( Mapa_enemigos[i]);
        }
        else if(i==2){
            Mapa_enemigos[i]=new Enemigos(10,450);
            scene2->addItem( Mapa_enemigos[i]);
        }
        else if(i==3){
            Mapa_enemigos[i]=new Enemigos(780,450);
            scene2->addItem( Mapa_enemigos[i]);
        }
    }


    connect(timer_mov,SIGNAL(timeout()),this,SLOT(mov_enemigos()));
    timer_mov->start(500);




}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if(e->key()==Qt::Key_A && p1->get_pos_x()>=63){

        p1->Mov_left();
    }
    else if(e->key()==Qt::Key_D && p1->get_pos_x()<737){
        p1->Mov_rigth();
    }
    else if(e->key()==Qt::Key_W && p1->get_pos_y()>=323){

        p1->Mov_up();
    }
    else if(e->key()==Qt::Key_S && p1->get_pos_y()<=537 ){

        p1->Mov_down();
    }
    else if(e->key()==Qt::Key_Space){


        QPixmap izquierda1(":/Morty/sprites/Morty/MortyIzquierda1.png");
        QPixmap derecha1(":/Morty/sprites/Morty/MortyDerecha1.png");
        QPixmap frente1(":/Morty/sprites/Morty/MortyFrente1.png");
        QPixmap detras1(":/Morty/sprites/Morty/MortyDetras1.png");
        if(*p1->get_mapa_sprite()==izquierda1 ){
            //DISPARA A LA IZQUIERDA
            bullet=new Proyectil_personaje(p1->get_pos_x(),p1->get_pos_y(),'l');
            scene2->addItem(bullet);

        }
        else if(*p1->get_mapa_sprite()==derecha1){
             //DISPARA A LA DERECHA
           bullet=new Proyectil_personaje(p1->get_pos_x(),p1->get_pos_y(),'r');
            scene2->addItem(bullet);
        }
        else if(*p1->get_mapa_sprite()==frente1){
             //DISPARA  LA ABAJO
           bullet=new Proyectil_personaje(p1->get_pos_x(),p1->get_pos_y(),'d');
           scene2->addItem(bullet);
        }
        else if(*p1->get_mapa_sprite()==detras1){
             //DISPARA A ARRIBA
           bullet=new Proyectil_personaje(p1->get_pos_x(),p1->get_pos_y(),'u');
           scene2->addItem(bullet);
        }


    }

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mov_enemigos()
{
    for(int i=0;i<4;i++){
        Mapa_enemigos[i]->persecucion_personaje(p1->x(),p1->y());
    }
}



