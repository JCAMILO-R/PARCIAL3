#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <particula.h>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
//incluir clase de los caniones
#include "caniond.h"
#include "caniono.h"
//incluir la libreria para graficar el circulo
#include<caniongrafico.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void DisparoCaso1();
    void ImprimirResultados(float angle, float x, float V0o, float y, int t);
    ~MainWindow();

private slots:
    void on_pntSimular_clicked();
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    QTimer *timer2;

    CanionO *canionO;//puntero de la clase Disparo Ofensivo
    CanionD *canionD;//puntero de la clase Disparo Defensivo

    Caniongrafico *cuerpocanionO;//puntero del circulo que representara el caño Ofensivo
    Caniongrafico *cuerporadiocanionO;//radio de impacto del canion ofensivo;
    Caniongrafico *cuerpocanionD;//puntero del circulo que representara el caño defensivo
    Caniongrafico *cuerporadiocanionD;//radio de impacto del canion defensivo;

    Caniongrafico *cuerpobala;

    //variable auxiliar para los casos
    int concasos=0;
     //variable auxiliares para el tiroparabolico
    double posx1=0;
    double posy1=0;
    double velocidad1=0;
    double angle1=0;

    Particula *cuerpo;
    QList<Particula *>Cuerpos;


    double x;
    double y;
    double v;
    double a;
    double v_x;
    double v_y;
    const double tiempo=0.01;
    const double g=9.8;

};

#endif // MAINWINDOW_H
