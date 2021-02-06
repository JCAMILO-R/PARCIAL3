#ifndef PARTICULA_H
#define PARTICULA_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>

class Particula :public QGraphicsItem
{
    double posx;
    double posy;
    double vel;
    double ang;
    double vel_x;
    double vel_y;
    const double tiempo=0.01;
    const double g=9.8;
    const int r=10;


public:
    Particula();
    Particula(double x, double y,double v, double a);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    double getPosy() const;
    void setPosy(double value);
    double getPosx() const;
    void setPosx(double value);
    void ActualizarPosicion();
    void CalcularVelocidad();

};

#endif // PARTICULA_H
