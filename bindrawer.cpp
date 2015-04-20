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
    if (!phase) return;

    int size = this->bin->getPackages()->size();
    int pos_y = size / 10;
    int pos_x = size % 10;
    if (size < 100) {
        Package *p = new Package(10,10,10 * pos_y,10 * pos_x ,size);
        this->bin->getPackages()->append(p);
    }
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
    QBrush brush(Qt::green);
    painter->setPen(QPen(Qt::red));

    painter->drawRect(rec);


    for (int i = 0; i < this->bin->getPackages()->size(); ++i) {
        Package *p = this->bin->getPackages()->at(i);
        qreal width = p->getDirection() == 0 ? p->getWidth():p->getHeight();
        qreal height = p->getDirection() == 1 ? p->getWidth():p->getHeight();
        width = width/this->bin->getWidth() * rec.width();
        height = height/this->bin->getHeight() * rec.height();
        qreal pos_x = p->getPosX()/this->bin->getHeight() * rec.height();
        qreal pos_y = p->getPosY()/this->bin->getWidth() * rec.width();
        QRectF package = QRectF(pos_y, rec.height() - height - pos_x, width, height);

        painter->fillRect(package, brush);
        painter->setPen(QPen(Qt::black));
        painter->drawRect(package);
    }
    //qreal
}

void BinDrawer::setBin(Bin *bin)
{
    this->bin = bin;
}
