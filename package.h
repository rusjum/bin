#ifndef PACKAGE_H
#define PACKAGE_H


class Package
{
public:
    Package();
    Package(double height, double width, int  id);
    Package(double height, double width, double pos_x, double pos_y, int  id);
    ~Package();

    double getWidth();
    void setWidth(double width);
    double getHeight();
    void setHeight(double height);
    double getPosX();
    void setPosX(double pos_x);
    double getPosY();
    void setPosY(double pos_y);
    int getDirection();
    void setDirection(int pos_y);


private:
    double width;
    double height;
    double pos_x;
    double pos_y;
    int id;
    int direction;
};

#endif // PACKAGE_H
