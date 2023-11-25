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
    estado_escena=true;
    ui->setupUi(this);
    nivel_0=new QGraphicsScene();
    ui->graphicsView->setScene(nivel_0);
    QImage fondo_0("inicio.jpeg");
    QBrush imagen(fondo_0);
    ui->graphicsView->setBackgroundBrush(imagen);
    nivel_0->setSceneRect(488,440,190,95);
    ui->graphicsView->scale(0.85,1);


    nivel_1=new QGraphicsScene();

    posicion_personaje_inicio();
    obstaculo();

    connect(timer_1, SIGNAL(timeout()), this, SLOT(actualizar_estado()));
    connect(timer_3, SIGNAL(timeout()), this, SLOT(movimiento_2_obstaculo()));
    connect(timer_2, SIGNAL(timeout()), this, SLOT(colicion()));







}

void MainWindow :: escena_1(){

    ui->graphicsView->setScene(nivel_1);
    QImage fondo_1("cancha_2.jpeg");
    QBrush fondo_pinta(fondo_1);
    ui->graphicsView->setBackgroundBrush(fondo_pinta);
    nivel_1->setSceneRect(169,350,295,87);
    ui->graphicsView->scale(1.420,1);
    inicio_juego();
}

void MainWindow :: inicio_juego(){

    timed.setHMS(0,3,20);
    ui->Cronometro->setText(timed.toString("m:ss"));
    timer_1->start(1000);
    timer_2->start(100);
    timer_3->start(500);
    avatar->setPos(320,610);
    linea_limite();
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-7 + rand()%(630-7);
        int rando_posy= -65 +rand()% (153-3);
        num=rando_pos;
        num_2=rando_posy;
        hola[i]->setPos(num,226);
    }
    cant_enemi=15;
    vely=10.18;

}

void MainWindow :: definir_final_de_juego(){
    msgbox.setWindowTitle("juego terminado");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.setStandardButtons(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::Yes);
    msgbox.setEscapeButton(QMessageBox::No);

    if(avatar->pos().y()<=226){
        timer_1->stop();
        timer_2->stop();
        timer_3->stop();
        msgbox.setText("haz perdido, ¿desea volver a jugar?");
        if(QMessageBox::Yes==msgbox.exec()){
            //crear metodo para inicarlizar el programa
             inicio_juego();

        }
        else{
            QCoreApplication::quit();
        }
    }
    else{
        if(timed.toString()=="00:00:00"){
            timer_1->stop();
            timer_3->stop();
            timer_2->stop();
        }
    }
}

void MainWindow::actualizar_cronometro(){
    timed=timed.addSecs(-1);
    ui->Cronometro->setText(timed.toString("m:ss"));
}

void MainWindow :: actualizar_enemigos(){
    if(timed.toString()=="00:03:18"){
        cant_enemi=15;
        vely=10.18;
    }
    if(timed.toString()=="00:03:00"){
        cant_enemi=20;
        vely=15.18;
    }
    if(timed.toString()=="00:02:30"){
        cant_enemi=30;
        vely=25.18;
    }
    if(timed.toString()=="00:02:00"){
        cant_enemi=40;
        vely=30.18;
    }
    if(timed.toString()=="00:01:30"){
        cant_enemi=50;
        vely=45.18;
    }
    if(timed.toString()=="00:00:30"){
        cant_enemi=60;
        vely=50.18;
    }
}

void MainWindow :: actualizar_estado(){
    actualizar_cronometro();
    definir_final_de_juego();
    actualizar_enemigos();
}

void MainWindow:: posicion_personaje_inicio(){
    QPixmap espalda("espalda.png");
    avatar=new QGraphicsPixmapItem();
    nivel_1->addItem(avatar);
    avatar-> setScale(0.4);
    avatar->setPixmap(espalda);
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
    if(avatar->pos().x()-6>=-8){
        avatar->setPos(avatar->pos().x()-6,avatar->pos().y());
        avatar->setPixmap(izquierda);
    }
    QTimer::singleShot(2500,this,SLOT(ESPALDA()));
    break;

    case Qt::Key_D:
    if(avatar->pos().x()+6<602){
        avatar->setPos(avatar->pos().x()+6,avatar->pos().y());
        avatar->setPixmap(derecha);
    }
    QTimer::singleShot(2500,this,SLOT(ESPALDA()));
    break;

    case Qt::Key_M:
    if(estado_escena==true){
        escena_1();
        estado_escena=false;
    }

    }


}

void MainWindow :: linea_limite(){
    QPen line(Qt::red,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    l1=nivel_1->addLine(-80,226,900,226,line);

}

void MainWindow :: obstaculo(){
    QPen line(Qt::red,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush inter(Qt::black);
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-7 + rand()%(630-7);
        int rando_posy= -75 +rand()% (153-3);
        num=rando_pos;
        num_2=rando_posy;
        auto *c= new QGraphicsEllipseItem(0,0,16,16);
        c->setBrush(inter);
        c->setPen(line);
        c->setPos(num,226);
        nivel_1->addItem(c);
        hola.push_back(c);

    }

}


void MainWindow :: movimiento_obstaculo(){
    int num,num_2;
    srand(time(NULL));
    for(int i=0;i<=cant_enemi;i++){
        y=vely+4.82+hola[i]->pos().y();
        hola[i]->setPos(hola[i]->pos().x(),y);
        if(hola[i]->pos().y()>=650){
            int rando_pos=-8 + rand()%(630-8);
            int rando_posy= -75 +rand()% (153-3);
            num=rando_pos;
            num_2=rando_posy;
            hola[i]->setPos(num,226);
        }
    }
}

void MainWindow ::colicion(){
    int num,num_2;
    srand(time(NULL));
    for(int i=0;i<=cant_enemi;i++){
        if(hola[i]->collidesWithItem(avatar)){
            avatar->setPos(320,avatar->pos().y()-60);
            for(int i=0;i<=cant_enemi;i++){
                int rando_pos=-8 + rand()%(630-8);
                int rando_posy= -75 +rand()% (153-3);
                num=rando_pos;
                num_2=rando_posy;
                hola[i]->setPos(num,num_2);
            }
        }
    }
}

void MainWindow :: movimiento_2_obstaculo(){
    angulo=angulo*(3.141592653/180);
    int h,posx;
    h=10*sin(angulo);
    posx=pow(10,2)-pow(h,2);
    posx=sqrt(posx);
    for(int i=0;i<=cant_enemi;i++){
        hola[i]->setPos(hola[i]->pos().x()-posx,hola[i]->pos().y()-h);
    }
    angulo+=25;
}


MainWindow::~MainWindow()
{
    delete ui;
}

