#include "ventana_finde_juego_nivel_2.h"
#include "ui_ventana_finde_juego_nivel_2.h"

Ventana_finde_juego_nivel_2::Ventana_finde_juego_nivel_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ventana_finde_juego_nivel_2)
{
    ui->setupUi(this);
}

Ventana_finde_juego_nivel_2::~Ventana_finde_juego_nivel_2()
{
    delete ui;
}

void Ventana_finde_juego_nivel_2::on_pushButton_clicked()
{

}

