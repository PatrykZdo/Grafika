#include "kolo.h"

Kolo::Kolo(){};

Kolo::Kolo(int cX,int cY,float R,int colorR, int colorG, int colorB,QImage *img){
    this->centerX=cX;
    this->centerY=cY;
    this->R=R;
    this->img=img;
    this->colorR=colorR;
    this->colorG=colorG;
    this->colorB=colorB;

    drawCircle(this->centerX,this->centerY,this->R,this->colorR,this->colorG,this->colorB,this->img);
}

Kolo::~Kolo(){};


int Kolo::getCenterX(){
    return this->centerX;
}

int Kolo::getCenterY(){
    return this->centerY;
}

float Kolo::getRadius(){
    return this->R;
}


void Kolo::drawCircle(int cX,int cY,float R,int colorR,int colorG,int colorB,QImage *img){
    int y=0,x=0;
    for(x;x<=floor(R/sqrt(2));x++){
        y=sqrt(pow(R,2)-pow(x,2));
        Pixel::drawPixel((x+cX),(y+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((-x+cX),(-y+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((x+cX),(-y+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((-x+cX),(y+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((y+cX),(-x+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((y+cX),(x+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((-y+cX),(x+cY),colorR,colorG,colorB,img);
        Pixel::drawPixel((-y+cX),(-x+cY),colorR,colorG,colorB,img);
    }
}
