#include "mainwindow.h"
#include "ui_mainwindow.h"



//CONSTRUCTOR
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Inicio_Nivel_2();

}

//METODOS NIVEL2
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
            vector_proyectiles[0]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());

            vector_proyectiles[0]->getTimer()->start(100);
            scene2->addItem(vector_proyectiles[0]);

        }
        else if(*p1->get_mapa_sprite()==derecha1){
             //DISPARA A LA DERECHA
            vector_proyectiles[1]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());

            vector_proyectiles[1]->getTimer()->start(100);
            scene2->addItem(vector_proyectiles[1]);
        }
        else if(*p1->get_mapa_sprite()==frente1){
             //DISPARA  LA ABAJO
            vector_proyectiles[2]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());

            vector_proyectiles[2]->getTimer()->start(100);
            scene2->addItem(vector_proyectiles[2]);
        }
        else if(*p1->get_mapa_sprite()==detras1){
             //DISPARA A ARRIBA
            vector_proyectiles[3]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());

            vector_proyectiles[3]->getTimer()->start(100);
            scene2->addItem(vector_proyectiles[3]);
        }


    }

}
void MainWindow::mover_enemigo_colisionado(int key)
{
    if(key==0){
        Mapa_enemigos[key]->Move_left();
        //Mapa_enemigos[key]->Move_up();
    }
    else if(key==1){
        //Mapa_enemigos[key]->Move_rigth();
        Mapa_enemigos[key]->Move_up();
    }
    else if(key==2){
        // Mapa_enemigos[key]->Move_left();
        Mapa_enemigos[key]->Move_down();
    }
    else if(key==3){
        Mapa_enemigos[key]->Move_rigth();
        //Mapa_enemigos[key]->Move_down();
    }
}

void MainWindow::mover_enemigo_colisionado_personaje(int key)
{
    if(Mapa_enemigos[key]->get_pos_x()> p1->get_pos_x()){
        Mapa_enemigos[key]->Move_rigth();
    }
    else if(Mapa_enemigos[key]->get_pos_x()< p1->get_pos_x()){
        Mapa_enemigos[key]->Move_left();
    }
    else{
        if(Mapa_enemigos[key]->get_pos_y()> p1->get_pos_y()){
           Mapa_enemigos[key]->Move_down();
        }
        else if(Mapa_enemigos[key]->get_pos_y()< p1->get_pos_y()){
           Mapa_enemigos[key]->Move_up();
        }
    }
}
void MainWindow::Nivel_2_terminado(bool win_lose)
{
    QString mensaje1="Ganaste!.\nClick en 'Yes' para volver a jugar.\nClick en 'Close' para cerrar",mensaje2="Perdiste :(..\nClick en 'Yes' para volver a jugar.\nClick en 'Close' para cerrar";
    timer_mov_colisiones_aparicion->stop();

    if(win_lose){
        msgbox->setText(mensaje1);
    }
    else{
        msgbox->setText(mensaje2);
    }
    msgbox->setWindowTitle("Juego Terminado");
    msgbox->setIcon(QMessageBox::Information);
    msgbox->setStandardButtons(QMessageBox::Yes);
    msgbox->addButton(QMessageBox::Close);
    msgbox->setDefaultButton(QMessageBox::Yes);
    msgbox->setEscapeButton(QMessageBox::Close);
    if(QMessageBox::Yes==msgbox->exec()){
        //Inicio Juego 1
    }
    else{
        QCoreApplication::quit();
    }

}

void MainWindow::Inicio_Nivel_2()
{
    scene2=new QGraphicsScene();
    scene2->setSceneRect(0,0,798,598);
    ui->graphicsView->setScene(scene2);

    QImage imagenFondo(":/Background/sprites/background/prueba.png");
    QBrush brochaFondo(imagenFondo);
    ui->graphicsView->setBackgroundBrush(brochaFondo);
    corazones.insert(0,new QGraphicsPixmapItem(*cora));
    corazones.insert(1,new QGraphicsPixmapItem(*cora));
    corazones.insert(2,new QGraphicsPixmapItem(*cora));

    //inicializacion proyectiles
    for(int i=0;i<4;i++){
        if(i==0){
           vector_proyectiles.insert(i,new Proyectil_personaje(0,0,'l'));
        }
        else if(i==1){
           vector_proyectiles.insert(i,new Proyectil_personaje(0,0,'r'));
        }
        else if(i==2){
           vector_proyectiles.insert(i,new Proyectil_personaje(0,0,'d'));
        }
        else if(i==3){
           vector_proyectiles.insert(i,new Proyectil_personaje(0,0,'u'));
        }

    }


    for(int i=0;i<3;i++){

        scene2->addItem(corazones[i]);
        corazones[i]->setPos(700+i*32,20);
    }


    p1=new Personaje (400,520);
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
           Mapa_enemigos[i]=new Enemigos(10,500);
           scene2->addItem( Mapa_enemigos[i]);
        }
        else if(i==3){
           Mapa_enemigos[i]=new Enemigos(780,500);
           scene2->addItem( Mapa_enemigos[i]);
        }
    }

    timer_cronometro=new QTimer();
    timer_mov_colisiones_aparicion=new QTimer();



    connect(timer_cronometro,SIGNAL(timeout()),this,SLOT(fin_dejuego()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_entre_enemigos()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(mov_enemigos()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_enemigo_personaje()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_enemigo_proyectil()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(aparicion_periodica_enemigos()));



    timer_mov_colisiones_aparicion->start(100);



    cuenta_regresiva.setHMS(0,1,30);
    ui->Cronometro->setText(cuenta_regresiva.toString("m:ss"));
    timer_cronometro->start(1000);
}
MainWindow::~MainWindow()
{

    delete timer_cronometro;
    delete timer_mov_colisiones_aparicion;

    for(int i=0;i<Mapa_enemigos.size();i++){
        delete Mapa_enemigos[i];
    }

    /*for(int i=0;i<3;i++){
        if(scene2->items().contains(corazones[i])){
           scene2->removeItem(corazones[i]);
        }

        delete corazones[i];
    }*/
    delete cora;
    for(int i=0;i<vector_proyectiles.size();i++){
        scene2->removeItem(vector_proyectiles[i]);
        delete vector_proyectiles[i];
    }
    delete p1;
    delete scene2;
    delete ui;



}


//METODOS SLOTS NIVEL2
void MainWindow::mov_enemigos()
{
    for(int i=0;i<4;i++){

        if(scene2->items().contains( Mapa_enemigos[i])){
           qDebug()<<"está en la escena";
           Mapa_enemigos[i]->persecucion_personaje(p1->get_pos_x() ,p1->get_pos_y());
        }
        else{
           qDebug()<<"se desplazo";
           Mapa_enemigos[i]->set_posiciones(100+20*i,700);
        }

    }

}

void MainWindow::colision_entre_enemigos()
{
    if(!Mapa_enemigos.isEmpty()){

        for(int i=0;i<4;i++){

           for(int j=0;j<4;j++){
               auto iterador=Mapa_enemigos.find(i);
               auto iterador2=Mapa_enemigos.find(j);
               if(i!=j){
                   if(iterador!=Mapa_enemigos.end() && iterador2!=Mapa_enemigos.end()){
                       if(Mapa_enemigos[i]->collidesWithItem(Mapa_enemigos[j])){
                           //qDebug()<<" Colision de "<<i<<" y"<<j;
                           mover_enemigo_colisionado(i);
                           mover_enemigo_colisionado(j);
                       }
                   }
               }
           }
        }
    }
}

void MainWindow::colision_enemigo_personaje()
{

    for(int i=0;i<Mapa_enemigos.size();i++){
        if(p1->collidesWithItem(Mapa_enemigos[i])){
           qDebug()<<p1->getVida();
           if(p1->getVida()>0){
               mover_enemigo_colisionado_personaje(i);
               p1->setVida(p1->getVida()-1);
               if(p1->getVida()==2){
                   delete corazones[0] ;
                   corazones.remove(0);
               }
               else if(p1->getVida()==1){
                   delete corazones[0] ;
                   corazones.remove(0);
               }
               else if(p1->getVida()==0){
                   delete corazones[0] ;
                   corazones.remove(0);
               }


           }
           else{
               timer_cronometro->stop();
               timer_mov_colisiones_aparicion->stop();
            Nivel_2_terminado(false);
           }
        }
    }
}

void MainWindow::colision_enemigo_proyectil()
{
    if(!Mapa_enemigos.empty()){
        for(int i=0;i<Mapa_enemigos.size();i++){
           for(int j=0;j<4;j++){
            if(scene2->items().contains(Mapa_enemigos[i])){
                if(Mapa_enemigos[i]->collidesWithItem(vector_proyectiles[j])){
                    qDebug()<<"Colision entre, proyectil"<<j<<"y enemigo"<<i;
                    scene2->removeItem(vector_proyectiles[j]);
                    qDebug()<<"se removio de la escena al proyectil: "<<j;
                     scene2->removeItem(Mapa_enemigos[i]);

                    qDebug()<<"se removio de la escena al enemigo: "<<i;



                }
            }
           }
        }
    }
}

void MainWindow::aparicion_periodica_enemigos()
{
    for(int i=0;i<Mapa_enemigos.size();i++){
        if(!scene2->items().contains( Mapa_enemigos[i])){
           qDebug()<<"No está en la escena";
           if(i==0){
            Mapa_enemigos[i]->set_posiciones(10,260);
           }
           else if(i==1){
            Mapa_enemigos[i]->set_posiciones(780,260);
           }
           else if(i==2){
            Mapa_enemigos[i]->set_posiciones(10,450);
           }
           else if(i==3){
            Mapa_enemigos[i]->set_posiciones(780,450);

           }
           scene2->addItem(Mapa_enemigos[i]);
        }
    }
}

void MainWindow::fin_dejuego()
{
    cuenta_regresiva=cuenta_regresiva.addSecs(-1);
    ui->Cronometro->setText(cuenta_regresiva.toString("m:ss"));
    if(cuenta_regresiva.toString()=="00:00:00"){
        timer_cronometro->stop();
        timer_mov_colisiones_aparicion->stop();
        Nivel_2_terminado(true);
    }
}











