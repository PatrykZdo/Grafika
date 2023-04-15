#ifndef KOLO_H
#define KOLO_H
#include "Pixel.h"

class Kolo{
private:
    int centerX;
    int centerY;
    int colorB;
    int colorG;
    int colorR;
    float R;
    QImage *img;

public:
    Kolo();
    Kolo(int,int,float,int,int,int,QImage *);
    ~Kolo();

    int getCenterX();
    int getCenterY();
    float getRadius();

    static void drawCircle(int,int,float,int,int,int,QImage *);
};
#endif // KOLO_H
