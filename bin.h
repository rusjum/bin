#ifndef BIN_H
#define BIN_H
#include <QVector>
#include "package.h"

class Bin
{
public:

    Bin();
    Bin(double height, double width, int  id);
    ~Bin();
    double getWidth();
    void setWidth(double width);
    double getHeight();
    void setHeight(double height);
    QVector<Package*> getPackages();

private:
    double width;
    double height;
    int id;
    QVector<Package*> *packages;
};

#endif // BIN_H
