#include "Pixel.h"

Pixel::Pixel(int x,int y,int *color,QImage *img){
    this->x=x;
    this->y=y;
    this->img=img;
    this->color=color;

    drawPixel(this->x,this->y,this->color,img);
};

void Pixel::drawPixel(int x,int y,int *color, QImage *img){
    unsigned char *ptr;
    ptr = img->bits();
    int szer = img->width();
    int wys = img->height();
    if(color[1]>255){
        color[1]=255;
    }
    else if(color[1]<0){
        color[1]=0;
    }

    if(color[2]>255){
        color[2]=255;
    }
    else if(color[2]<0){
        color[2]=0;
    }

    if(color[0]>255){
        color[0]=255;
    }
    else if(color[0]<0){
        color[0]=0;
    }

    if(x>=szer||x<0||y>=wys||y<0){
        return ;
    }

    ptr[szer*4*y + 4*x]=color[0];
    ptr[szer*4*y + 4*x + 1] = color[1];
    ptr[szer*4*y + 4*x + 2] = color[2];
}
