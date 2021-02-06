#ifndef CANIONGRAFICO_H
#define CANIONGRAFICO_H
#include <QGraphicsItem>
#include<QPainter>

class Caniongrafico:public QGraphicsItem
{
    int r;
    int posX;
    int posY;
    int numero;
public:
    Caniongrafico(int _r,int _posx, int _posy,int _numero);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

};

#endif // CANIONGRAFICO_H
