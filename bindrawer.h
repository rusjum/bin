#ifndef BINDRAWER_H
#define BINDRAWER_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "bin.h"


class BinDrawer : public QGraphicsItem
{
public:
    BinDrawer();
    BinDrawer(qreal init_x, qreal init_y);
    ~BinDrawer();
    void advance(int phase);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setBin(Bin* bin);
private:
    Bin* bin;
};

#endif // BINDRAWER_H
