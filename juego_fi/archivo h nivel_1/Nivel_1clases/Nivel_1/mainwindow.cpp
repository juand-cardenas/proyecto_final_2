#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    crear_grupo_de_bolitas();

    //control de escena
    estado_escena=true;

    //ESCENA PRE_JUEGO
    scene1->setSceneRect(10,10,750,530);
    ui->graphicsView->setScene(scene1);
    QImage fondo_0(":/imagenes_juego/pre_juego.jpg");
    QBrush brocha_fondo_0(fondo_0);
    scene1->setBackgroundBrush(brocha_fondo_0);

    //Timers
    connect(timer_1, SIGNAL(timeout()), this, SLOT(actualizar_estado()));
    connect(timer_2, SIGNAL(timeout()), this, SLOT(colicion()));
    connect(timer_3, SIGNAL(timeout()), this, SLOT(tipo_movimiento_del_obstaculo()));

}

MainWindow::~MainWindow()
{
    delete timer_cronometro_2;
    delete timer_mov_colisiones_aparicion;

    for(int i=0;i<Mapa_enemigos.size();i++){
        delete Mapa_enemigos[i];
    }

    /*for(int i=0;i<3;i++){
        delete corazones[i];
    }*/
    corazones.clear();
    delete cora;
    for(int i=0;i<vector_proyectiles.size();i++){
        //qDebug()<<vector_proyectiles.size();
        delete vector_proyectiles[i];
    }
    vector_proyectiles.clear();
    delete p1;
    delete scene2;
    delete ui;
}

void MainWindow::escena1()
{
    ui->graphicsView->setGeometry(0,0,771,551);
    scene1->setSceneRect(0,0,769,549);

    personaje->setScale(0.39);
    scene1->addItem(personaje);
    ui->graphicsView->setScene(scene1);
    QImage fondo_1(":/imagenes_juego/cancha_2_copy.jpeg");
    QBrush fondo_pinta(fondo_1);
    ui->graphicsView->setBackgroundBrush(fondo_pinta);
    scene1->setSceneRect(262,244,170,90);
    //ui->graphicsView->scale(1.149,0.988);

    linea_limite();
    inicio_juego();


}

void MainWindow:: crear_grupo_de_bolitas(){
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-27 + rand()%(689-27);
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
    timed.setHMS(0,3,25);
    ui->Cronometro->setText(timed.toString("m:ss"));
    timer_1->start(1000);
    timer_2->start(100);
    timer_3->start(500);
    size_t n=90;
    int num,num_2;
    srand(time(NULL));
    for (size_t i=0;i<n;i++){
        int rando_pos=-26 + rand()%(746);
        int rando_posy=-110 +rand()% (120-3);
        num=rando_pos;
        num_2=rando_posy;
        bolitas[i]->colocar_posiciones(num,num_2);
    }
    tipo_de_movimiento=1 +rand()% (3-1);
    personaje->reinicio_posicion(338,537);
    cant_enemigos=15;
    auxiliar.setVel_y(10.18);
    //auxiliar.setAngulo();

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

    if(nivel_actual==true){
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
    else{
        if(e->key()==Qt::Key_A && p1->get_pos_x()>=63){

            p1->Mov_left();
        }
        else if(e->key()==Qt::Key_D && p1->get_pos_x()<737){
            p1->Mov_rigth();
        }
        else if(e->key()==Qt::Key_W && p1->get_pos_y()>=323){

            p1->Mov_up();
        }
        else if(e->key()==Qt::Key_S && p1->get_pos_y()<500 ){

            p1->Mov_down();
        }
        else if(e->key()==Qt::Key_Space){


            QPixmap izquierda1(":/Morty/sprites/Morty/MortyIzquierda1.png");
            QPixmap derecha1(":/Morty/sprites/Morty/MortyDerecha1.png");
            QPixmap frente1(":/Morty/sprites/Morty/MortyFrente1.png");
            QPixmap detras1(":/Morty/sprites/Morty/MortyDetras1.png");
            if(*p1->get_mapa_sprite()==izquierda1 ){
                //DISPARA A LA IZQUIERDA
                if(scene2->items().contains(vector_proyectiles[0])){

                    vector_proyectiles[0]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[0]->getTimer()->start(100);


                }
                else{
                    vector_proyectiles[0]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[0]->getTimer()->start(100);
                    scene2->addItem(vector_proyectiles[0]);
                }
            }
            else if(*p1->get_mapa_sprite()==derecha1){
                //DISPARA A LA DERECHA
                if(scene2->items().contains(vector_proyectiles[1])){

                    vector_proyectiles[1]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[1]->getTimer()->start(100);

                }
                else{

                    vector_proyectiles[1]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[1]->getTimer()->start(100);
                    scene2->addItem(vector_proyectiles[1]);
                }

            }
            else if(*p1->get_mapa_sprite()==frente1){
                //DISPARA  LA ABAJO
                if(scene2->items().contains(vector_proyectiles[2])){
                    vector_proyectiles[2]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[2]->getTimer()->start(100);

                }
                else{

                    vector_proyectiles[2]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                    vector_proyectiles[2]->getTimer()->start(100);
                    scene2->addItem(vector_proyectiles[2]);
                }


            }
            else if(*p1->get_mapa_sprite()==detras1){
                //DISPARA A ARRIBA
                if(scene2->items().contains(vector_proyectiles[3])){

                vector_proyectiles[3]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                vector_proyectiles[3]->getTimer()->start(100);

                }
                else{

                vector_proyectiles[3]->set_posiciones(p1->get_pos_x(),p1->get_pos_y());
                vector_proyectiles[3]->getTimer()->start(100);
                scene2->addItem(vector_proyectiles[3]);
                }

            }


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
            int rando_pos=-26 + rand()%(746);
            int rando_posy= -110 +rand()% (120-3);
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
        auxiliar.setMovi_x(2.3);
        auxiliar.setMovi_y(1.5);
        //movi_x=2.3;
        //movi_y=1.5;
    }
    if(timed.toString()=="00:03:00"){
        cant_enemigos=20;
        auxiliar.setVel_y(15.18);
        auxiliar.setMovi_x(2.8);
        auxiliar.setMovi_y(2);
        //movi_x=2.8;
        //movi_y=2;
    }
    if(timed.toString()=="00:02:30"){
        cant_enemigos=30;
        auxiliar.setVel_y(25.18);
        auxiliar.setMovi_x(3.4);
        auxiliar.setMovi_y(2.5);
        //movi_x=3.4;
        //movi_y=2.5;
    }
    if(timed.toString()=="00:02:00"){
        cant_enemigos=40;
        auxiliar.setVel_y(30.18);
        auxiliar.setMovi_x(4);
        auxiliar.setMovi_y(3);
        //movi_x=4;
        //movi_y=3;
    }
    if(timed.toString()=="00:01:30"){
        cant_enemigos=50;

        auxiliar.setVel_y(45.18);
        auxiliar.setMovi_x(4.7);
        auxiliar.setMovi_y(3.5);
        //movi_x=4.7;
        //movi_y=3.5;
    }
    if(timed.toString()=="00:00:30"){
        cant_enemigos=60;
        auxiliar.setVel_y(50.18);
        auxiliar.setMovi_x(5.5);
        auxiliar.setMovi_y(4);
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
                int rando_pos=-26 + rand()%(746);
                int rando_posy= -110 +rand()% (120-3);
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
            nivel_actual=false;
            ui->Cronometro->hide();
            ui->Cronometro_2->show();
            Inicio_Nivel_2();
        }
    }
}

void MainWindow :: movimiento_bolitas_2(){
    int num,num_2;
    srand(time(NULL));

    if(auxiliar.getAngulo()<=1.570){

        int h,posx;
        h=auxiliar.getRadio()*sin(auxiliar.getAngulo());
        posx=pow(auxiliar.getRadio(),2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemigos;i++){
            //hola[i]->setPos(hola[i]->pos().x()-posx,hola[i]->pos().y()-movi_y*h);
            bolitas[i]->setPos_y(bolitas[i]->getPos_y()-(auxiliar.getMovi_y()*h));
            bolitas[i]->setPos_x(bolitas[i]->getPos_x()-(auxiliar.getMovi_x()*posx));
            bolitas[i]->colocar_posiciones(bolitas[i]->getPos_x(),bolitas[i]->getPos_y());
        }
    }

    if(auxiliar.getAngulo()>=1.570 && auxiliar.getAngulo() <=3.14159){

        int h,posx;
        h=auxiliar.getRadio()*sin(auxiliar.getAngulo());
        posx=pow(auxiliar.getRadio(),2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemigos;i++){
            //hola[i]->setPos(hola[i]->pos().x()-movi_x*posx,hola[i]->pos().y()+movi_x*h);
            bolitas[i]->setPos_y(bolitas[i]->getPos_y()+(auxiliar.getMovi_y()*h));
            bolitas[i]->setPos_x(bolitas[i]->getPos_x()-(auxiliar.getMovi_x()*posx));
            bolitas[i]->colocar_posiciones(bolitas[i]->getPos_x(),bolitas[i]->getPos_y());
        }

    }

    if(auxiliar.getAngulo()>=3.14159 && auxiliar.getAngulo()<=4.71238){

        int h,posx;
        h=auxiliar.getRadio()*sin(auxiliar.getAngulo());
        posx=pow(auxiliar.getRadio(),2)-pow(h,2);
        posx=sqrt(posx);
        for(int i=0;i<=cant_enemigos;i++){
            //hola[i]->setPos(hola[i]->pos().x()+movi_x*posx,hola[i]->pos().y()-movi_x*h);
            bolitas[i]->setPos_x(bolitas[i]->getPos_x()+(auxiliar.getMovi_x()*posx));
            bolitas[i]->setPos_y(bolitas[i]->getPos_y()-(auxiliar.getMovi_x()*h));
            bolitas[i]->colocar_posiciones(bolitas[i]->getPos_x(),bolitas[i]->getPos_y());
        }

    }

    if(auxiliar.getAngulo()>=4.71238 && auxiliar.getAngulo()<=5.6831853){

        int h,posx;
        h=auxiliar.getRadio()*sin(auxiliar.getAngulo());
        posx=pow(auxiliar.getRadio(),2)-pow(h,2);
        posx=(posx);
        for(int i=0;i<=cant_enemigos;i++){
            //hola[i]->setPos(hola[i]->pos().x()+posx,hola[i]->pos().y()+movi_y*h);
            bolitas[i]->setPos_x(bolitas[i]->getPos_x()+posx);
            bolitas[i]->setPos_y(bolitas[i]->getPos_y()+(auxiliar.getMovi_y()*h));
            bolitas[i]->colocar_posiciones(bolitas[i]->getPos_x(),bolitas[i]->getPos_y());
            if(bolitas[i]->getPos_y()>=650){
                int rando_pos=-26 + rand()%(746);
                int rando_posy= -110 +rand()% (120-3);
                num=rando_pos;
                num_2=rando_posy;
                bolitas[i]->colocar_posiciones(num,num_2);
            }
        }

    }


    if(auxiliar.getAngulo()>5.7831853){
        auxiliar.setAngulo(0);

    }

    //angulo+=0.5872664;
    auxiliar.setAngulo(auxiliar.getAngulo()+0.5872664);

}


void MainWindow::tipo_movimiento_del_obstaculo(){
    if(tipo_de_movimiento==1){
        movimiento_bolitas_2();
    }
    if(tipo_de_movimiento==2){
        movimiento_bolitas();
    }
}

//  NIVEL 2 METODOS Y SLOTS
//METODOS
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
        Msgbox->setText(mensaje1);
    }
    else{
        Msgbox->setText(mensaje2);
    }
    Msgbox->setWindowTitle("Juego Terminado");
    Msgbox->setIcon(QMessageBox::Information);
    Msgbox->setStandardButtons(QMessageBox::Yes);
    Msgbox->addButton(QMessageBox::Close);
    Msgbox->setDefaultButton(QMessageBox::Yes);
    Msgbox->setEscapeButton(QMessageBox::Close);
    if(QMessageBox::Yes==Msgbox->exec()){
        //Inicio Juego 1
        ui->Cronometro_2->hide();
        ui->Cronometro->show();
        nivel_actual=true;
        escena1();
    }
    else{
        QCoreApplication::quit();
    }

}

void MainWindow::Inicio_Nivel_2()
{
    scene2=new QGraphicsScene();

    ui->graphicsView->setGeometry(0,0,800,600);

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

    timer_cronometro_2=new QTimer();
    timer_mov_colisiones_aparicion=new QTimer();



    connect(timer_cronometro_2,SIGNAL(timeout()),this,SLOT(fin_dejuego()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_entre_enemigos()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(mov_enemigos()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_enemigo_personaje()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(colision_enemigo_proyectil()));
    connect(timer_mov_colisiones_aparicion,SIGNAL(timeout()),this,SLOT(aparicion_periodica_enemigos()));



    timer_mov_colisiones_aparicion->start(100);



    cuenta_regresiva.setHMS(0,1,30);
    ui->Cronometro_2->setText(cuenta_regresiva.toString("m:ss"));
    timer_cronometro_2->start(1000);
}

//METODOS SLOTS NIVEL2
void MainWindow::mov_enemigos()
{
    for(int i=0;i<4;i++){

        if(scene2->items().contains( Mapa_enemigos[i])){
            //qDebug()<<"está en la escena";
                        Mapa_enemigos[i]->persecucion_personaje(p1->get_pos_x() ,p1->get_pos_y());
        }
        else{
            //qDebug()<<"se desplazo";
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
                            ////qDebug()<<" Colision de "<<i<<" y"<<j;
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
            //qDebug()<<p1->getVida();
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
                timer_cronometro_2->stop();
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
                        //qDebug()<<"Colision entre, proyectil"<<j<<"y enemigo"<<i;
                        //scene2->removeItem(vector_proyectiles[j]);
                        //qDebug()<<"se removio de la escena al proyectil: "<<j;
                        scene2->removeItem(Mapa_enemigos[i]);

                        //qDebug()<<"se removio de la escena al enemigo: "<<i;



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
            //qDebug()<<"No está en la escena";
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
    ui->Cronometro_2->setText(cuenta_regresiva.toString("m:ss"));
    if(cuenta_regresiva.toString()=="00:00:00"){
        timer_cronometro_2->stop();
        timer_mov_colisiones_aparicion->stop();
        Nivel_2_terminado(true);
    }
}
