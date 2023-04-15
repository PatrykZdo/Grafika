#ifndef LINIA_H
#define LINIA_H

#include <QImage>

class Linia{
private:
    int startX;
    int startY;
    int endX;
    int endY;

    int colorR;
    int colorG;
    int colorB;

    QImage *img;

public:
    Linia();
    Linia(int,int,int,int,int,int,int,QImage*);
    ~Linia();

    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();

    static void drawLine(int,int,int,int,int,int,int,QImage*);

};

#endif // LINIA_H
