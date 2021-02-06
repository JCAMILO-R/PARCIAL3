
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>//para poder imprimir en consola
#include <math.h>
#include <cmath>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,800,600);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);
    timer = new QTimer();
    timer2 = new QTimer();

    timer->start(5);
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));



}

void MainWindow::DisparoCaso1()
{
    int contador=0;
    int flag =0;
    float x,y;
    int t=0;
    int angle =0;
    for (angle =0; angle <90;angle++){//for del angulo
        a=(angle*3.14159)/180;//escalar el angulo
        for(v=10;v<=150;v+=10){//aumentar la velocidad
            v_x=v*cos(a);//calcular la velocidad de x inicial
            v_y=v*sin(a)-g*tiempo;//calcular la velocidad de y inicial
            v=sqrt(pow(v_y,2)+pow(v_x,2));//valcular la raiz de la velocidad
            x=0.0;//pos x
            y=0.0;//pos y
            for(t=0; ; t++){//transcurrir el tiempo
                x=v_x*t;//velocidad x al transcurrir el tiempo
                y=v_y*t-(0.5*g*t*t);//velocidad y al transcurrir el tiempo
                if(sqrt(pow((canionO->Xo+100-x),2)+pow((-canionO->Ho+550-y),2))<canionD->d0){//condision de colision
                    contador++;
                    if(contador==1){//crear la bala con la primer colision que se encuentra
                        posx1=canionO->Xo+100;
                        posy1=550-canionO->Ho;
                        velocidad1=v;
                        angle1=angle;
                    }
                    if(y<0)y=0;
                    ImprimirResultados(a, x, v, y, t);//imprimir resultados de las colisiones
                    flag +=1;
                    v +=10;//cambia la velocidad inicial del disparo para el proximo calculo
                    break;
                }
                if(y<0){
                    break;
                }
            }
            if(flag==3)break;
             }
        if(flag==3) break;
    }
    if(flag!=3){
        cout <<"No impacto en los disparos esperados"<<endl;
    }

}

void MainWindow::ImprimirResultados(float angle, float x, float V0o, float y, int t)
{
    qDebug()<<"Impacto con un Angulo de "<<angle<<" grados"<<endl;
    qDebug()<<"Impacto con velocidad inicial "<<V0o<<endl;
    qDebug()<<"Impacto con posicion x: "<<x<<endl;
    qDebug()<<"Impacto con posicion y: "<<y<<endl;
    qDebug()<<"Con tiempo: "<<t<<endl;
    qDebug()<<endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pntSimular_clicked()
{
    escena->removeItem(cuerpo);
    concasos=1;
    qDebug()<<"aqui estoy"<<endl;
    double x=ui->ho->text().toDouble();
    double y=ui->hd->text().toDouble();
    double z=ui->distancia->text().toDouble();
    canionD =new CanionD(z,y);//constructor de disparo Defensivo con parametros iniciales
    canionO= new CanionO(z,x);//constructor de disparo Ofensivo con parametros iniciales
    cuerpocanionO=new Caniongrafico(25,canionO->Xo+100,550-canionO->Ho,0);//dibujo representativo del cañon
    cuerporadiocanionO=new Caniongrafico(25+canionO->d0,canionO->Xo+100,550-canionO->Ho,1);//dibujo representativo de la area del cañon
    cuerpocanionD=new Caniongrafico(25,canionD->Xd+100,550-canionD->Hd,2);
    cuerporadiocanionD = new Caniongrafico(25+canionD->d0,canionD->Xd+100,550-canionD->Hd,3);
    //agregar a la scena los circulos que representan los cañones
    escena->addItem(cuerporadiocanionO);
    escena->addItem(cuerpocanionO);
    escena->addItem(cuerporadiocanionD);
    escena->addItem(cuerpocanionD);
    posx1=0;
    posy1=0;
    velocidad1=0;
    angle1=0;
    DisparoCaso1();
    double a=((angle1+5)*3.14159)/180;
    cuerpo= new Particula(posx1,-posy1,velocidad1,a);
    escena->addItem(cuerpo);
}

void MainWindow::mover()
{
    if(concasos==1){
    cuerpo->ActualizarPosicion();
    }
}


