#ifndef PACKAGEDRAWER_H
#define PACKAGEDRAWER_H
#include <QPainter>
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "package.h"

class PackageDrawer : public QGraphicsItem
{
public:
    PackageDrawer();
    PackageDrawer(qreal init_x, qreal init_y, qreal max);
    ~PackageDrawer();

    // QGraphicsItem interface
public:
    void advance(int phase);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPackages(QVector<Package*> *packages);
    QVector<Package *> *getPackages();
private:
    QVector<Package*> *packages;
    qreal max;
};

#endif // PACKAGEDRAWER_H
