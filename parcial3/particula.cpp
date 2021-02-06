#include "particula.h"
#include<QDebug>

double Particula::getPosy() const
{
    return posy;
}

void Particula::setPosy(double value)
{
    posy = value;
}

double Particula::getPosx() const
{
    return posx;
}

void Particula::setPosx(double value)
{
    posx = value;
}

void Particula::ActualizarPosicion()
{
    CalcularVelocidad();
    posx=posx+vel_x*tiempo;
    posy=posy+vel_y*tiempo-(0.5*g*tiempo+tiempo);
    setPos(posx,-posy);
}

void Particula::CalcularVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*tiempo;
    ang=atan2(vel_y,vel_x);
    vel=sqrt(pow(vel_y,2)+pow(vel_x,2));
}

Particula::Particula()
{

}

Particula::Particula(double x, double y, double v, double a)
{
    posx=x;
    posy=y;
    vel=v;
    ang= a/90;
    setPos(posx,posy);
    qDebug()<<"posx "<<posx<<" posy "<<posy<<" vel "<<v<<" angle "<<ang<<endl;

}

QRectF Particula::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Particula::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(Qt::red);
  painter->drawEllipse(boundingRect());
}
