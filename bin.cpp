#include "bin.h"

Bin::Bin()
{

}

Bin::Bin(double height, double width, int id)
{
    this->height = height;
    this->width = width;
    this->id = id;
    this->packages = new QVector<Package*>();
}

Bin::~Bin()
{

}

double Bin::getWidth()
{
    return this->width;
}

void Bin::setWidth(double width)
{
    this->width = width;
}

double Bin::getHeight()
{
    return this->height;
}

void Bin::setHeight(double height)
{
    this->height = height;
}

QVector<Package *>* Bin::getPackages()
{
    return this->packages;
}

