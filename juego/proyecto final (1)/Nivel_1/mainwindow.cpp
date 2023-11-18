#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>
#include <time.h>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nivel_1=new QGraphicsScene();
    ui->graphicsView->setScene(nivel_1);

    QImage fondo_1("cancha_2.jpeg");
    QBrush fondo_pinta(fondo_1);
    ui->graphicsView->setBackgroundBrush(fondo_pinta);
    nivel_1->setSceneRect(215,360,215,95);
    ui->graphicsView->scale(1.136,1.133);

    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar_estado()));
    connect(timer_3, SIGNAL(timeout()), this, SLOT(movimiento_obstaculo()));

    obstaculo();
    posicion_personaje_inicio();



}

void MainWindow :: definir_final_de_juego(){
    msgbox.setWindowTitle("Jueo terminado");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.setStandardButtons(QMessageBox:: Yes);
    msgbox.addButton(QMessageBox:: No);
    msgbox.setDefaultButton(QMessageBox:: Yes);
    msgbox.setEscapeButton(QMessageBox:: No);

    if(timed.toString()=="00:00:00"){
        timer->stop();
        msgbox.setText("Haz ganado ");

    }
}

void MainWindow::actualizar_cronometro(){
    timed=timed.addSecs(-1);
    ui->Cronometro->setText(timed.toString("m:ss"));
}

void MainWindow :: actualizar_enemigos(){

}

void MainWindow :: actualizar_estado(){
    actualizar_cronometro();
    definir_final_de_juego();

}

void MainWindow:: posicion_personaje_inicio(){
    timed.setHMS(0,3,20);
    ui->Cronometro->setText(timed.toString("m:ss"));
    timer->start(1000);
    timer_3->start(500);
    QPixmap espalda("espalda.png");
    avatar=new QGraphicsPixmapItem();
    nivel_1->addItem(avatar);
    avatar-> setScale(0.4);
    avatar->setPixmap(espalda);
    avatar->setPos(320,590);
    linea_limite();
}

void MainWindow:: ESPALDA(){
    QPixmap espalda("espalda.png");
    avatar->setPixmap(espalda);
}


void MainWindow :: keyPressEvent(QKeyEvent *e){
    QPixmap izquierda("Izquierda.png");
    QPixmap derecha("Derecha.png");
    switch(e->key()){
    case Qt::Key_A:
        if(avatar->pos().x()-6>=-22){
            avatar->setPos(avatar->pos().x()-6,avatar->pos().y());
            avatar->setPixmap(izquierda);

        }
        QTimer::singleShot(2500,this,SLOT(ESPALDA()));
        break;

    case Qt::Key_D:
    if(avatar->pos().x()+6<622){
            avatar->setPos(avatar->pos().x()+6,avatar->pos().y());
            avatar->setPixmap(derecha);

        }
        QTimer::singleShot(2500,this,SLOT(ESPALDA()));
        break;
    }

}

void MainWindow :: linea_limite(){
    QPen line(Qt::red,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    l1=nivel_1->addLine(-16,226,800,226,line);

}

void MainWindow :: obstaculo(){
    QPen line(Qt::red,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush inter(Qt::black);
    size_t n=70;
    int d=-8,num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-8 + rand()%(630-8);
        int rando_posy= -50 +rand()% (103-3);
        num=rando_pos;
        num_2=rando_posy;
        auto *c= new QGraphicsEllipseItem(0,0,16,16);
        c->setBrush(inter);
        c->setPen(line);
        c->setPos(num,num_2);
        nivel_1->addItem(c);
        hola.push_back(c);
        d+=8;
    }

}


void MainWindow :: movimiento_obstaculo(){
    int num,num_2;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        hola[i]->setPos(hola[i]->pos().x(),hola[i]->pos().y()+12);
    if(hola[i]->pos().y()>=650){
            int rando_pos=-8 + rand()%(630-8);
            int rando_posy= -50 +rand()% (103-3);
            num=rando_pos;
            num_2=rando_posy;
            hola[i]->setPos(num,num_2);

    }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

