#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <cmath>
using namespace std;
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer_1=new QTimer();
    QTimer *timer_2=new QTimer();
    QTimer *timer_3=new QTimer();
    QTime timed;
    QMessageBox msgbox;

    void keyPressEvent(QKeyEvent *e);

private slots:

    void escena_1();
    void definir_final_de_juego();
    void actualizar_estado();
    void actualizar_cronometro();
    void posicion_personaje_inicio();
    void ESPALDA();
    void linea_limite();
    void obstaculo();
    void movimiento_obstaculo();
    void actualizar_enemigos();
    void colicion();
    void inicio_juego();
    void movimiento_2_obstaculo();
    void tipo_movimiento_del_obstaculo();

private:

    int tipo_de_movimiento;
    int radio=15;
    int movi_y;
    int movi_x;
    float angulo=0;
    bool estado_escena;
    int cant_enemi;
    float vely;
    float y;
    Ui::MainWindow *ui;
    QGraphicsScene *nivel_1,*nivel_0;
    QGraphicsPixmapItem *avatar;
    QGraphicsLineItem *l1;
    vector<QGraphicsEllipseItem*>hola={};

};
#endif // MAINWINDOW_H
