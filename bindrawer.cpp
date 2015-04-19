#include "bindrawer.h"

BinDrawer::BinDrawer()
{

}

BinDrawer::~BinDrawer()
{

}



void BinDrawer::advance(int phase)
{
}

QRectF BinDrawer::boundingRect() const
{
    if (this->bin != NULL) {

        qreal scene_width = this->scene()->width();
        qreal scene_height = this->scene()->height();
        int bin_width = this->bin->width;
        int bin_height = this->bin->height;
        qreal minRel = qMin(scene_height/bin_height, scene_width/bin_width);
    }
}

void BinDrawer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
}
