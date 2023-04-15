#include "mainwindowf.h"
#include "ui_mainwindowf.h"
#include "Linia.h"
#include "kolo.h"
#include "Pixel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <utility>
#include <unistd.h>



using namespace  std;

MainWindowF::MainWindowF(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle("FloodFill");

    resize(800,700);

    this->szer = 600;
    this->wys = 600;
    this->posx = 25;
    this->posy = 25;

    img = new QImage(szer,wys,QImage::Format_RGB32);
    bg = new QImage(szer,wys,QImage::Format_RGB32);
    clean();

    grupa = new QGroupBox("Sterowanie",this);
    grupa->setGeometry(QRect(posx+szer+posx,posy,800-szer-2*posx,posy+250));

    QVBoxLayout *boxLayout = new QVBoxLayout;

    linia_przycisk = new QPushButton("Linia");
    kolo_przycisk = new QPushButton("Kolo");
    clean_przycisk = new QPushButton("Clean");
    fill_przycisk = new QPushButton("Zamaluj");

    boxLayout -> addWidget(linia_przycisk);
    boxLayout -> addWidget(kolo_przycisk);
    boxLayout -> addWidget(clean_przycisk);
    boxLayout -> addWidget(fill_przycisk);

    grupa -> setLayout(boxLayout);

    connect(linia_przycisk,SIGNAL(clicked()),this,SLOT(slot_linia()));
    connect(kolo_przycisk,SIGNAL(clicked()),this,SLOT(slot_kolo()));
    connect(clean_przycisk,SIGNAL(clicked()),this,SLOT(clean()));
    connect(fill_przycisk,SIGNAL(clicked()),this,SLOT(slot_fill()));
}

MainWindowF::~MainWindowF()
{
    delete img;
    delete bg;
    delete colors;
}

void MainWindowF::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawImage(posx,posy,*img);
}

//slots

void MainWindowF::slot_linia(){
    this->pointer='L';
    update();
}

void MainWindowF::slot_kolo(){
    this->pointer='K';
    update();
}

void MainWindowF::slot_fill(){
    this->pointer='M';
    update();
}


//function

void MainWindowF::clean(){
    srand(time(NULL));
    this -> colorR = rand() % 256;
    this -> colorG = rand() % 256;
    this -> colorB = rand() % 256;

    unsigned char *ptr;
            ptr = img->bits();

            int i,j;
            for(i=0; i<wys; i++)
            {
                for(j=0; j<szer; j++)
                {
                    ptr[szer*4*i + 4*j]=colorB; // Skladowa BLUE
                    ptr[szer*4*i + 4*j + 1] = colorG; // Skladowa GREEN
                    ptr[szer*4*i + 4*j + 2] = colorR; // Skladowa RED
                }
            }
    update();
}

void MainWindowF::copy(QImage* img,QImage* bg){
    int x=img->width();
    int y=img->height();
    for(int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            bg->bits()[szer*4*j + 4*i]=img->bits()[szer*4*j + 4*i];
            bg->bits()[szer*4*j + 4*i+1]=img->bits()[szer*4*j + 4*i+1];   //funkcja kopjujaca "obrazy"
            bg->bits()[szer*4*j + 4*i+2]=img->bits()[szer*4*j + 4*i+2];
        }
    }
}

int *MainWindowF::color(int x, int y){
    int *colors = new int[3];
    unsigned char *ptr;
    ptr = img -> bits();

    colors[0] = ptr[szer*4*y + 4*x];
    colors[1] = ptr[szer*4*y + 4*x + 1];
    colors[2] = ptr[szer*4*y + 4*x + 2];

    return colors;

}

void MainWindowF::fill(int x, int y, int R, int G, int B){
    pixels.push({x,y});
    pair<int, int> XY;
    int *RGB = new int[3];
    XY=pixels.top();
    colors = color(XY.first,XY.second);
    RGB[2]=colors[2];
    RGB[1]=colors[1];
    RGB[0]=colors[0];


    while(!pixels.empty()){
        XY=pixels.top();
        RGB = color(XY.first,XY.second);
        if(RGB[2] == colors[2]  &&  RGB[1] == colors[1]  &&  RGB[0] == colors[0]){

            Pixel::drawPixel(XY.first,XY.second,R,G,B,img);
            update();
            pixels.pop();

            RGB = color(XY.first+1,XY.second);
            if(RGB[2] == colors[2]  &&  RGB[1] == colors[1]  &&  RGB[0] == colors[0] && XY.first+1<600 && XY.first +1> 0 && XY.second<599 && XY.second > 0){
                pixels.push({XY.first+1, XY.second});
            }
            RGB = color(XY.first-1,XY.second);
            if(RGB[2] == colors[2]  &&  RGB[1] == colors[1]  &&  RGB[0] == colors[0] && XY.first-1<600 && XY.first-1 > 0 && XY.second<599 && XY.second > 0){
                pixels.push({XY.first-1, XY.second});
            }
            RGB = color(XY.first,XY.second+1);
            if(RGB[2] == colorR  &&  RGB[1] == colorG  &&  RGB[0] == colorB && XY.first<600 && XY.first > 0 && XY.second+1<599 && XY.second+1 > 0){
                pixels.push({XY.first, XY.second+1});
            }
            RGB = color(XY.first,XY.second-1);
            if(RGB[2] == colors[2]  &&  RGB[1] == colors[1]  &&  RGB[0] == colors[0] && XY.first<600 && XY.first > 0 && XY.second-1<599 && XY.second-1 > 1){
                pixels.push({XY.first, XY.second-1});
            }
        }
        cout<<XY.first<<" "<<XY.second<<endl;
        sleep(0.5);

    }
    delete RGB;
}

//mouse events

void MainWindowF::mousePressEvent(QMouseEvent *e){
    copy(img,bg);
    unsigned char *ptr;
    ptr = img->bits();

    this->startX = e -> x() - posx;
    this->startY = e -> y()- posy;

    if(pointer == 'M'){

        int new_colorB = rand() % 256;
        int new_colorG = rand() % 256;
        int new_colorR = rand() % 256;

        int x,y;
        x=e->x() - posx;
        y=e->y() - posy;
        this -> colors = MainWindowF::color(x,y);
        //cout<<x<<" "<<y<<endl;
        fill(x,y,255,255,255);

    }
}

void MainWindowF::mouseMoveEvent(QMouseEvent *e){
    this->endX = e->x()-posx;
    this->endY= e->y()-posy;
    copy(bg,img);

        switch(this->pointer){
        case 'L':{
                Linia::drawLine(this->startX,this->startY,this->endX,this->endY,0,0,0,img);
                }
           break;



        case 'K':{
                float R=sqrt(pow((endX-startX),2)+pow((endY-startY),2));
                Kolo::drawCircle(startX,startY,R,0,0,0,img);
                }
            break;
        default:
                    Pixel::drawPixel(endX,endY,0,0,0,img);

            }
            update();
}

void MainWindowF::mouseReleaseEvent(QMouseEvent *e){
    this->endX = e->x()-posx;
    this->endY= e->y()-posy;

        switch(this->pointer){
        case 'L':{
                Linia::drawLine(this->startX,this->startY,this->endX,this->endY,0,0,0,img);
                }
           break;



        case 'K':{
                float R=sqrt(pow((endX-startX),2)+pow((endY-startY),2));
                Kolo::drawCircle(startX,startY,R,0,0,0,img);
                }
            break;
        default:
                    Pixel::drawPixel(endX,endY,0,0,0,img);

            }
            update();
}
