#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena1();
    linea_limite();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::escena1()
{
    scene1->setSceneRect(0,0,769,549);

    personaje->setScale(0.39);
    scene1->addItem(personaje);
    ui->graphicsView->setScene(scene1);
    QImage fondo_1("cancha_2_copy.jpeg");
    QBrush fondo_pinta(fondo_1);
    ui->graphicsView->setBackgroundBrush(fondo_pinta);
    scene1->setSceneRect(262,244,170,90);
    ui->graphicsView->scale(1.149,0.988);
    scene1->addItem(bolitam);
    //crear_grupo_de_bolitas();



}

void MainWindow:: crear_grupo_de_bolitas(){
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-7 + rand()%(630-7);
        int rando_posy= -90 +rand()% (153-3);
        num=rando_pos;
        num_2=rando_posy;
        bolita *c= new bolita(num,num_2);
        bolitas.push_back(c);
        scene1->addItem(bolitas[i]);


    }
}

void MainWindow :: linea_limite(){
    QPen line(Qt::red,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    l1=scene1->addLine(-80,120,900,120,line);

}

