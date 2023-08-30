#ifndef DRAWPIXEL_H
#define DRAWPIXEL_H

#include "QImage"

class Pixel{
private:

    int x;
    int y;
    int *color;
    QImage *img;

public:

    Pixel();
    Pixel(int x,int y,int *color,QImage*);
    ~Pixel();

    static void drawPixel(int x,int y,int *color,QImage*);

};

#endif // DRAWPIXEL_H
