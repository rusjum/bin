#include "bindrawer.h"

BinDrawer::BinDrawer()
{
}

BinDrawer::BinDrawer(qreal init_x, qreal init_y)
{
    setPos(mapToParent(init_x, init_y));


}

BinDrawer::~BinDrawer()
{

}



void BinDrawer::advance(int phase)
{
    if (phase % 2)
        this->scene()->clear();
    else
        this->scene()->addItem(this);

}

QRectF BinDrawer::boundingRect() const
{
    qreal scene_width = this->scene()->width();
    qreal scene_height = this->scene()->height();

    if (this->bin != NULL) {

        int bin_width = this->bin->getWidth();
        int bin_height = this->bin->getHeight();
        // count min relation (width/heigth) to bin
        qreal min_rel = qMin(scene_height*0.5/bin_height, scene_width*0.5/bin_width);
        return QRectF(0, 0, min_rel * bin_width, min_rel * bin_height);
    } else {

        int bin_width = 50;
        int bin_height = 50;
        // count min relation (width/heigth) to bin
        qreal min_rel = qMin(scene_height*0.5/bin_height, scene_width*0.5/bin_width);
        return QRectF(0, 0, min_rel * bin_width, min_rel * bin_height);
    }

}

void BinDrawer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rec = boundingRect();
    setPos(this->scene()->width()*0.2, this->scene()->height()-rec.height() - 10);
    QBrush brush(Qt::red);
    painter->setPen(QPen(Qt::red));
    painter->drawRect(rec);
}

void BinDrawer::setBin(Bin *bin)
{
    this->bin = bin;
}
