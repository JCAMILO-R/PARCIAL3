#include "caniongrafico.h"



Caniongrafico::Caniongrafico(int _r, int _posx, int _posy, int _numero)
{
    r =_r;
    posX=_posx;
    posY=_posy;
    numero=_numero;
    setPos(posX,posY);
}

QRectF Caniongrafico::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Caniongrafico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(numero == 0){
    painter->setBrush(Qt::green);
    }
    else if (numero==1) {
        painter->setBrush(Qt::blue);
    }
    else if(numero==2){
        painter->setBrush(Qt::red);
    }
    else if(numero==3){
        painter->setBrush(Qt::green);
    }
    else if(numero==4){
        painter->setBrush(Qt::black);
    }
    painter->drawEllipse(boundingRect());
}
