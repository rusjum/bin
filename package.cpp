#include "package.h"

Package::Package()
{

}

Package::Package(double height, double width, int id)
{
    this->height = height;
    this->width = width;
    this->id = id;
    this->direction = 0;
}

Package::Package(double height, double width, double pos_x, double pos_y, int id)
{
    this->height = height;
    this->width = width;
    this->id = id;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->direction = 0;
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

double Package::getPosX()
{
    return this->pos_x;
}

void Package::setPosX(double pos_x)
{
    this->pos_x = pos_x;
}

double Package::getPosY()
{
    return this->pos_y;
}

void Package::setPosY(double pos_y)
{
    this->pos_y = pos_y;
}

int Package::getDirection()
{
    return this->direction;
}

void Package::setDirection(int direction)
{
    this->direction = direction;
}
