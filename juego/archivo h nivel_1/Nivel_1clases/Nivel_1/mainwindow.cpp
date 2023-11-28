#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    linea_limite();
    crear_grupo_de_bolitas();

    //control de escena
    estado_escena=true;

    //Timers
    connect(timer_1, SIGNAL(timeout()), this, SLOT(actualizar_estado()));
    connect(timer_2, SIGNAL(timeout()), this, SLOT(colicion()));
    connect(timer_3, SIGNAL(timeout()), this, SLOT(movimiento_bolitas()));

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
    //scene1->addItem(bolitam);

    inicio_juego();


}

void MainWindow:: crear_grupo_de_bolitas(){
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=27 + rand()%(689-27);
        int rando_posy= -100 +rand()% (6-3);
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

void MainWindow :: inicio_juego(){
    timed.setHMS(0,3,20);
    ui->Cronometro->setText(timed.toString("m:ss"));
    timer_1->start(1000);
    timer_2->start(100);
    timer_3->start(500);
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-7 + rand()%(630-7);
        int rando_posy= -95 +rand()% (153-3);
        num=rando_pos;
        num_2=rando_posy;
        bolitas[i]->colocar_posiciones(num,num_2);
    }
    personaje->reinicio_posicion(338,537);
    cant_enemigos=15;
    auxiliar.setVel_y(10.18);

}

void MainWindow::actualizar_cronometro(){
    timed=timed.addSecs(-1);
    ui->Cronometro->setText(timed.toString("m:ss"));
}

void MainWindow :: actualizar_estado(){
    actualizar_cronometro();
    definir_final_de_juego();
    actualizar_enemigos();
}


void MainWindow :: keyPressEvent(QKeyEvent *e){

    switch(e->key()){
    case Qt::Key_A:
        if(personaje->getPos_x()>27){
        personaje->movimiento_izquierda();

        }
        break;

    case Qt::Key_D:
        if(personaje->getPos_x()<660){
         personaje->movimiento_derecha();
        }
        break;

    case Qt::Key_M:
        if(estado_escena==true){
            escena1();
            estado_escena=false;
        }

    }


}

void MainWindow:: movimiento_bolitas(){
    int num,num_2;
    srand(time(NULL));
    for(int i=0;i<=cant_enemigos;i++){
        bolitas[i]->setPos_y( auxiliar.getVel_y()+4.82+bolitas[i]->getPos_y());
        bolitas[i]->colocar_posiciones(bolitas[i]->getPos_x(),bolitas[i]->getPos_y());
        if(bolitas[i]->getPos_y()>=540){
            int rando_pos=27 + rand()%(689-27);
            int rando_posy= -95 +rand()% (153-3);
            num=rando_pos;
            num_2=rando_posy;
            bolitas[i]->colocar_posiciones(num,num_2);
        }
    }
}

void MainWindow :: actualizar_enemigos(){
    if(timed.toString()=="00:03:18"){
        cant_enemigos=15;

        auxiliar.setVel_y(10.18);
        //movi_x=2.3;
        //movi_y=1.5;
    }
    if(timed.toString()=="00:03:00"){
        cant_enemigos=20;
        auxiliar.setVel_y(15.18);
        //movi_x=2.8;
        //movi_y=2;
    }
    if(timed.toString()=="00:02:30"){
        cant_enemigos=30;
        auxiliar.setVel_y(25.18);
        //movi_x=3.4;
        //movi_y=2.5;
    }
    if(timed.toString()=="00:02:00"){
        cant_enemigos=40;
        auxiliar.setVel_y(30.18);
        //movi_x=4;
        //movi_y=3;
    }
    if(timed.toString()=="00:01:30"){
        cant_enemigos=50;

        auxiliar.setVel_y(45.18);
        //movi_x=4.7;
        //movi_y=3.5;
    }
    if(timed.toString()=="00:00:30"){
        cant_enemigos=60;
        auxiliar.setVel_y(50.18);
        //movi_x=5.5;
        //movi_y=4;
    }
}

void MainWindow ::colicion(){
    int num,num_2;
    srand(time(NULL));
    for(int i=0;i<=cant_enemigos;i++){
        if(bolitas[i]->collidesWithItem(personaje)){
            //avatar->setPos(320,avatar->pos().y()-60);
            personaje->movimiento_arriba();
            for(int i=0;i<=cant_enemigos;i++){
                int rando_pos=-8 + rand()%(630-8);
                int rando_posy= -95 +rand()% (153-3);
                num=rando_pos;
                num_2=rando_posy;
                bolitas[i]->colocar_posiciones(num,num_2);
            }
        }
    }
}

void MainWindow :: definir_final_de_juego(){
    msgbox.setWindowTitle("juego terminado");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.setStandardButtons(QMessageBox::Yes);
    msgbox.addButton(QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::Yes);
    msgbox.setEscapeButton(QMessageBox::No);

    if(personaje->getPos_y()<=120){
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

void MainWindow :: movimiento_bolitas_2(){
    int num,num_2;
    srand(time(NULL));

    if(angulo<1.570){

        int h,posx;
        h=radio*sin(angulo);
        posx=pow(radio,2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemi;i++){
            hola[i]->setPos(hola[i]->pos().x()-posx,hola[i]->pos().y()-movi_y*h);
        }
    }
    if(angulo>=1.570 and angulo <=3.14159){

        int h,posx;
        h=radio*sin(angulo);
        posx=pow(radio,2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemi;i++){
            hola[i]->setPos(hola[i]->pos().x()-movi_x*posx,hola[i]->pos().y()+movi_x*h);
        }

    }

    if(angulo>=3.14159 and angulo<=4.71238){

        int h,posx;
        h=radio*sin(angulo);
        posx=pow(radio,2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemi;i++){
            hola[i]->setPos(hola[i]->pos().x()+movi_x*posx,hola[i]->pos().y()-movi_x*h);
        }

    }
    if(angulo>=4.71238 and angulo<6.2831853){

        int h,posx;
        h=radio*sin(angulo);
        posx=pow(radio,2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemi;i++){
            hola[i]->setPos(hola[i]->pos().x()+posx,hola[i]->pos().y()+movi_y*h);
            if(hola[i]->pos().y()>=650){
                int rando_pos=-8 + rand()%(630-8);
                int rando_posy= -75 +rand()% (153-3);
                num=rando_pos;
                num_2=rando_posy;
                hola[i]->setPos(num,num_2);
            }
        }

    }
    if(angulo>6.2831853){
        angulo=0;

    }

    angulo+=0.5872664;

}
