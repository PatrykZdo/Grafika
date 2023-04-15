#ifndef PIXEL_H
#define PIXEL_H

#include <Qimage>

class Pixel{
private:

    int x;
    int y;
    int colorB;
    int colorG;
    int colorR;

    QImage *img;


public:

    Pixel();
    Pixel(int, int, QImage*, int, int, int);
    ~Pixel();

    static void drawPixel(int, int, int, int, int, QImage*);
};

#endif // PIXEL_H
