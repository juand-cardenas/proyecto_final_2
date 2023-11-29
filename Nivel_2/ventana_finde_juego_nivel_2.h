#ifndef VENTANA_FINDE_JUEGO_NIVEL_2_H
#define VENTANA_FINDE_JUEGO_NIVEL_2_H

#include <QDialog>

namespace Ui {
class Ventana_finde_juego_nivel_2;
}

class Ventana_finde_juego_nivel_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Ventana_finde_juego_nivel_2(QWidget *parent = nullptr);
    ~Ventana_finde_juego_nivel_2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Ventana_finde_juego_nivel_2 *ui;
};

#endif // VENTANA_FINDE_JUEGO_NIVEL_2_H
