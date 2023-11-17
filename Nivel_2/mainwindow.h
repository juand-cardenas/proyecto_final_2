#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include<personaje.h>
#include<enemigos.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *e);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene2;
    QGraphicsLineItem *l1,*l2;
    QGraphicsPixmapItem *personaje;
    QPixmap pm;
    Enemigos *e;
    Personaje *p1,*p2;
};
#endif // MAINWINDOW_H
