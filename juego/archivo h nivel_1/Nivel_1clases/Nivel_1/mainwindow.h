#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMap>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include<QVector>
#include <vector>
#include "personaje_nivel_1.h"
#include "bolita.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //METODOS PRIVADOS
    void escena1();
    void crear_grupo_de_bolitas();
    void linea_limite();
//-------------------------------------------------------------------------
    Ui::MainWindow *ui;
    QGraphicsScene *scene1=new QGraphicsScene;
    personaje_nivel1 * personaje=new personaje_nivel1(338,537);
    bolita *bolitam=new bolita(200,155);
    QGraphicsLineItem *l1;
    vector<bolita *>bolitas={};// crear vector de bolitas
};
#endif // MAINWINDOW_H
