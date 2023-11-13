#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>


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
    posicion_personaje_inicio();


}

void MainWindow :: definir_final_de_juego(){
    msgbox.setWindowTitle("Jueo terminado");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.setStandardButtons(QMessageBox:: Yes);
    msgbox.addButton(QMessageBox:: No);
    msgbox.setDefaultButton(QMessageBox:: Yes);
    msgbox.setEscapeButton(QMessageBox:: No);

    if(time.toString()=="00:00:00"){
        timer->stop();
        msgbox.setText("Haz ganado ");

    }
}

void MainWindow::actualizar_cronometro(){
    time=time.addSecs(-1);
    ui->Cronometro->setText(time.toString("m:ss"));
}

void MainWindow :: actualizar_estado(){
    actualizar_cronometro();
    definir_final_de_juego();

}

void MainWindow:: posicion_personaje_inicio(){
    time.setHMS(0,3,20);
    ui->Cronometro->setText(time.toString("m:ss"));
    timer->start(1000);
    QPixmap espalda("espalda.png");
    avatar=new QGraphicsPixmapItem();
    nivel_1->addItem(avatar);
    avatar-> setScale(0.4);
    avatar->setPixmap(espalda);
    avatar->setPos(320,590);
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



MainWindow::~MainWindow()
{
    delete ui;
}

