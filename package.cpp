#include "package.h"

Package::Package()
{

}

Package::Package(double height, double width, int id)
{
    this->height = height;
    this->width = width;
    this->id = id;
}

Package::~Package()
{

}

double Package::getWidth()
{
    return this->width;
}

void Package::setWidth(double width)
{
    this->width = width;
}

double Package::getHeight()
{
    return this->height;
}

void Package::setHeight(double height)
{
    this->height = height;
}

