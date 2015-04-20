#include "packagedrawer.h"

PackageDrawer::PackageDrawer()
{

}

PackageDrawer::PackageDrawer(qreal init_x, qreal init_y, qreal max)
{
    setPos(mapToScene(init_x, init_y));
    this->max = max;
    packages = new QVector<Package*>();


}

PackageDrawer::~PackageDrawer()
{

}

QRectF PackageDrawer::boundingRect() const
{
    qreal scene_width = this->scene()->width();
    qreal scene_height = this->scene()->height();
    return QRectF(0, 0, scene_width, scene_height);
}

void PackageDrawer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qreal gap = 10;
    qreal x = gap;
    qreal y = gap;
    qreal next_y  = 0;
    QRectF rect = boundingRect();
    for (int i = 0; i < this->packages->size(); ++i) {

        Package *p = this->packages->at(i);
        if (p->getWidth() + x > rect.width())
        {
            y += next_y + gap;
            next_y = 0;
            x = gap;
        }
        painter->fillRect(x, y, p->getWidth(), p->getHeight(), QBrush(Qt::red));
        x += p->getWidth() + gap;
        if (next_y < p->getHeight())
            next_y = p->getHeight();
    }

}

void PackageDrawer::advance(int phase)
{
    if (!phase) return;
    int size = this->getPackages()->size();

    if (size < 10) {
        Package *p = new Package(10*size ,10*size,10,10,size);
        this->getPackages()->append(p);
    }
}


void PackageDrawer::setPackages(QVector<Package *> *packages)
{
    this->packages = packages;
}

QVector<Package *> *PackageDrawer::getPackages()
{
    return this->packages;
}
