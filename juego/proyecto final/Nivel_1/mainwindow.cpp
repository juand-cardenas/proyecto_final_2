#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>
#include <time.h>


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
    //connect(timer_2, SIGNAL(timeout()), this, SLOT(obstaculo()));
    //obstaculo();

    posicion_personaje_inicio();

    int rando_pos;
    srand(time(NULL));
    rando_pos=-8+rand()%(636+8);
    QPen line(Qt::black,4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush inter(Qt::black);
    c1=nivel_1->addEllipse(0,0,12,12,line,inter);
    c1->setPos(rando_pos,160);

    connect(timer_3, SIGNAL(timeout()), this, SLOT(movimiento_obstaculo()));



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

void MainWindow :: actualizar_estado(){
    actualizar_cronometro();
    definir_final_de_juego();

}

void MainWindow:: posicion_personaje_inicio(){
    timed.setHMS(0,3,20);
    ui->Cronometro->setText(timed.toString("m:ss"));
    timer->start(1000);
    timer_2->start(1000);
    timer_3->start(100);
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

    int rando_pos;
    srand(time(NULL));
    rando_pos=-8+rand()%(636+8);
    QPen line(Qt::black,4,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush inter(Qt::black);
    c1=nivel_1->addEllipse(0,0,12,12,line,inter);
    c1->setPos(rando_pos,160);

    connect(timer_3, SIGNAL(timeout()), this, SLOT(movimiento_obstaculo()));

}

void MainWindow :: movimiento_obstaculo(){

    c1->setPos(c1->pos().x(),c1->pos().y()+2);
    if(c1->pos().y()+4>522){
        nivel_1->removeItem(c1);


    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

