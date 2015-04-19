#ifndef PACKAGE_H
#define PACKAGE_H


class Package
{
public:
    Package();
    Package(double height, double width, int  id);
    ~Package();

    double getWidth();
    void setWidth(double width);
    double getHeight();
    void setHeight(double height);
private:
    double width;
    double height;
    int id;
};

#endif // PACKAGE_H
