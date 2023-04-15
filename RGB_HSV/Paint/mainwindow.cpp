#include "mainwindow.h"
#include <QVBoxLayout>
#include <QSlider>
#include <iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //Ustawiamy tytul okna
    setWindowTitle("Paint");

    //Rozmiary okna
    resize(800,700);

    //Ustawiamy wymiary obrazka
    this->szer = 600;
    this->wys = 600;
    this->poczX = 25;
    this->poczY = 25;

    img = new QImage(szer,wys,QImage::Format_RGB32);
    clean(img);

    //grupa elementow zwiazanych z opcjami
    grupaOpcje = new QGroupBox("Opcje", this);
    grupaOpcje->setGeometry(QRect(poczX + szer + poczX, poczY, 800 - szer - 2*poczX, poczY+100));
    QVBoxLayout *boxLayoutOpcje = new QVBoxLayout;

    //Przyciski
    RGB_Button = new QPushButton("RGB");
    HSV_Button = new QPushButton("HSV");


    //Dodajemy przyciski do layout
    boxLayoutOpcje -> addWidget(RGB_Button);
    boxLayoutOpcje -> addWidget(HSV_Button);


    //Dodajemy layout do grupy
    grupaOpcje -> setLayout(boxLayoutOpcje);


    //Połaczenia przycizk z akcja
    connect(RGB_Button, SIGNAL(clicked()), this, SLOT(RGB_colorPicker()));
    connect(HSV_Button, SIGNAL(clicked()), this, SLOT(HSV_colorPicker()));



                                //RGB

    //grupa elementow zwiazanych z RGB Color Picker'em
    grupaRGB = new QGroupBox("RGB", this);
    grupaRGB -> setGeometry(QRect(poczX + szer + poczX, poczY+ 120,800 -szer - 2*poczX, poczY + 300));
    QHBoxLayout *boxLayoutRGB = new QHBoxLayout;

    //Slidery do RGB
    sliderR = new QSlider(Qt::Vertical,this);
    sliderG = new QSlider(Qt::Vertical,this);
    sliderB = new QSlider(Qt::Vertical,this);

    //Ustawianie wlasciwosci sliderow
    // Red Slider
    sliderR -> setMaximum(255);
    sliderR -> setMinimum(0);
    // Green Slider
    sliderG -> setMaximum(255);
    sliderG -> setMinimum(0);
    // Blue Slider
    sliderB -> setMaximum(255);
    sliderB -> setMinimum(0);

    //Dodajnie Sliderow do layout
    boxLayoutRGB -> addWidget(sliderR);
    boxLayoutRGB -> addWidget(sliderG);
    boxLayoutRGB -> addWidget(sliderB);

    //Dodajemy layout do grupy
    grupaRGB -> setLayout(boxLayoutRGB);

    //Ustawienie widocznosci grupy
    grupaRGB -> setVisible(false);

    //CONNECTS
    connect(sliderR, SIGNAL(sliderPressed()), this, SLOT(sliderR_pressed()));
    connect(sliderG, SIGNAL(sliderPressed()), this, SLOT(sliderG_pressed()));
    connect(sliderB, SIGNAL(sliderPressed()), this, SLOT(sliderB_pressed()));

    connect(sliderR, SIGNAL(valueChanged(int)), this, SLOT(sliderR_changed()));
    connect(sliderG, SIGNAL(valueChanged(int)), this, SLOT(sliderG_changed()));
    connect(sliderB, SIGNAL(valueChanged(int)), this, SLOT(sliderB_changed()));





                                //HSV

    //grupa elementow zwiazanych z HSV Color Picker'em
    grupaHSV = new QGroupBox("HSV",this);
    grupaHSV -> setGeometry(QRect(poczX + szer + poczX, poczY+ 120,800 -szer - 2*poczX, poczY + 300));
    QHBoxLayout *boxLayoutHSV = new QHBoxLayout;

    //Slidery do HSV
    sliderH = new QSlider(Qt::Vertical,this);
    sliderS = new QSlider(Qt::Vertical,this);
    sliderV = new QSlider(Qt::Vertical,this);

    //Ustawianie wlasciwosci sliderow
    // Hue Slider
    sliderH -> setMaximum(360);
    sliderH -> setMinimum(0);
    // Saturation Slider
    sliderS -> setMaximum(1000);
    sliderS -> setMinimum(0);
    // Value Slider
    sliderV -> setMaximum(1000);
    sliderV -> setMinimum(0);

    //Dodajnie Sliderow do layout
    boxLayoutHSV -> addWidget(sliderH);
    boxLayoutHSV -> addWidget(sliderS);
    boxLayoutHSV -> addWidget(sliderV);

    //Dodajemu layout do grupy
    grupaHSV -> setLayout(boxLayoutHSV);

    //Ustawienie widocznosci grupy
    grupaHSV -> setVisible(false);

    //CONNECTS
    connect(sliderH, SIGNAL(sliderPressed()), this, SLOT(sliderH_pressed()));
    connect(sliderS, SIGNAL(sliderPressed()), this, SLOT(sliderS_pressed()));
    connect(sliderV, SIGNAL(sliderPressed()), this, SLOT(sliderV_pressed()));

    connect(sliderH, SIGNAL(valueChanged(int)), this, SLOT(sliderH_changed()));
    connect(sliderS, SIGNAL(valueChanged(int)), this, SLOT(sliderS_changed()));
    connect(sliderV, SIGNAL(valueChanged(int)), this, SLOT(sliderV_changed()));





}

MainWindow::~MainWindow()
{
    delete img;
}

void MainWindow:: paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(poczX,poczY,*img);
}




//Funkcje potrzebne do CONNECT

//RGB
void MainWindow:: RGB_colorPicker()
{
    grupaHSV -> setVisible(false);
    grupaRGB -> setVisible(true);
    sliderR -> setValue(0);
    sliderG -> setValue(0);
    sliderB -> setValue(0);
    colorMixerRGB('R',sliderR -> value());
    update();
}

void MainWindow:: sliderR_pressed()
{
    pointer = 'R';
    colorMixerRGB(pointer, sliderR -> value());
    update();
}

void MainWindow:: sliderG_pressed()
{
    pointer = 'G';
    colorMixerRGB(pointer, sliderG -> value());
    update();
}

void MainWindow:: sliderB_pressed()
{
    pointer = 'B';
    colorMixerRGB(pointer,sliderR -> value());
    update();
}

void MainWindow:: sliderR_changed()
{
    colorMixerRGB(pointer, sliderR -> value());
    update();
}

void MainWindow:: sliderG_changed()
{
    colorMixerRGB(pointer, sliderG -> value());
    update();
}

void MainWindow:: sliderB_changed()
{
    colorMixerRGB(pointer, sliderB -> value());
    update();
}


//HSV
void MainWindow:: HSV_colorPicker()
{
    grupaRGB -> setVisible(false);
    grupaHSV -> setVisible(true);
    sliderH -> setValue(0);
    sliderS -> setValue(0);
    sliderV -> setValue(0);
    colorMixerHSV('H', sliderH -> value());
    update();
}


void MainWindow:: sliderH_pressed()
{
    pointer = 'H';
    colorMixerHSV(pointer, sliderH -> value());
    update();
}

void MainWindow:: sliderS_pressed()
{
    pointer = 'S';
    colorMixerHSV(pointer, sliderS -> value());
    update();
}

void MainWindow:: sliderV_pressed()
{
    pointer = 'V';
    colorMixerHSV(pointer,sliderV -> value());
    update();
}

void MainWindow:: sliderH_changed()
{
    colorMixerHSV(pointer, sliderH -> value());
    update();
}

void MainWindow:: sliderS_changed()
{
    colorMixerHSV(pointer, sliderS -> value());
    update();
}

void MainWindow:: sliderV_changed()
{
    colorMixerHSV(pointer, sliderV -> value());
    update();
}



//Funkcje wykonujace jakies zadania

void MainWindow::clean(QImage *img)
{
    unsigned char *ptr;
        ptr = img->bits();

        int i,j;
        for(i=0; i<wys; i++)
        {
            for(j=0; j<szer; j++)
            {
                ptr[szer*4*i + 4*j]=255; // Skladowa BLUE
                ptr[szer*4*i + 4*j + 1] = 255; // Skladowa GREEN
                ptr[szer*4*i + 4*j + 2] = 255; // Skladowa RED
            }
        }
}


void MainWindow:: colorMixerRGB(char znak,int wartosc=0)
{
    if(znak == 'R'){
        float blue = 0;

        for(int i=0;i<wys;i++){
            float green = 255;
            for (int j=0; j<this->szer; j++){
                Pixel::drawPixel(i,j,round(blue),green,wartosc,img);
                green = green - (255.0/szer);
            }
            blue = blue + (255.0/wys);

        }
    }

    else if(znak == 'G'){
        float blue = 0;
        for(int i=0;i<=wys;i++){
            float red = 255;
            for (int j=0; j<=szer; j++){
                Pixel::drawPixel(i,j,blue,wartosc,red,img);
                red = red - (255.0/szer);
            }
            blue = blue + (255.0/wys);
        }
    }

    else if(znak == 'B'){
        float red = 0;
        for(int i=0;i<=wys;i++){
            float green = 255;
            for (int j=0; j<=szer; j++){
                Pixel::drawPixel(i,j,wartosc,green,red,img);
                green = green - (255.0/szer);
            }
            red = red + (255.0/wys);
        }
    }
    else{
        clean(img);
    }
}



void MainWindow:: colorMixerHSV(char znak, float wartosc)
{
    if(znak == 'H'){
        float S = 0;
        for(int i=0; i<wys; i++){
            float V =1;
            for(int j=0; j<szer; j++){
                convert(wartosc,S,V,i,j);
                V = V-(1.0/szer);
            }
            S = S + (1.0/wys);
        }
    }else if(znak == 'S'){
        float V = 1;
        for (int i=0;i<wys;i++){
            float H = 0;
            for(int j=0;j<szer;j++){
                convert(H,wartosc/1000.0,V,j,i);
                H = H + (360.0/szer);
            }
            V = V - (1.0/wys);
        }
    }else if(znak == 'V'){
        float S = 1;
        for (int i=0;i<wys;i++){
            float H = 0;
            for(int j=0;j<szer;j++){
                convert(H,S,wartosc/1000.0,j,i);
                H = H + (360.0/szer);
            }
            S = S - (1.0/wys);
        }
    }

}


void MainWindow::convert(float h, float s, float v, int i, int j)
{
    float chroma;
    float h_prim;
    float x;
    float RGB[3];
    chroma = v * s;
    h_prim = h / 60.0;
    x = chroma * (1 - abs(fmod(h_prim,2) - 1));

    if(0 <= h_prim && h_prim <= 1){
        RGB[0]=(chroma + (v-chroma))*255;
        RGB[1]=(x + (v-chroma))*255;
        RGB[2]=(0 + (v-chroma))*255;
    }else if(1 < h_prim && h_prim <= 2){
        RGB[0]=(x + (v-chroma))*255;
        RGB[1]=(chroma + (v-chroma))*255;
        RGB[2]=(0 + (v-chroma))*255;
    }else if(2 < h_prim && h_prim <=3){
        RGB[0]=(0 + (v-chroma))*255;
        RGB[1]=(chroma + (v-chroma))*255;
        RGB[2]=(x + (v-chroma))*255;
    }else if(3 < h_prim && h_prim <=4){
        RGB[0]=(0 + (v-chroma))*255;
        RGB[1]=(x + (v-chroma))*255;
        RGB[2]=(chroma + (v-chroma))*255;
    }else if(4 < h_prim && h_prim <=5){
        RGB[0]=(x + (v-chroma))*255;
        RGB[1]=(0 + (v-chroma))*255;
        RGB[2]=(chroma + (v-chroma))*255;
    }else if(5 < h_prim && h_prim <=6){
        RGB[0]=(chroma + (v-chroma))*255;
        RGB[1]=(0 + (v-chroma))*255;
        RGB[2]=(x + (v-chroma))*255;
    }else{
        RGB[0] = 0 + (v-chroma);
        RGB[1] = 0 + (v-chroma);
        RGB[2] = 0 + (v-chroma);
    }
    Pixel::drawPixel(i,j,RGB[2],RGB[1],RGB[0],img);
}


// MouseMoveEvents

void MainWindow:: mousePressEvent(QMouseEvent *event)
{
    unsigned char *ptr;
    ptr = img->bits();
    int colorB,colorG,colorR;

    int x,y;
    x=event->x();
    y=event->y();

    colorB=ptr[szer*4*x + 4*y];
    colorG=ptr[szer*4*x + 4*y + 1];
    colorR=ptr[szer*4*x + 4*y + 2];

    cout<<colorB<<endl;
    cout<<colorG<<endl;
    cout<<colorR<<endl;
}

void MainWindow:: mouseMoveEvent(QMouseEvent *event)
{
    unsigned char *ptr;
    ptr = img->bits();

    int x,y;
    x=event->x()-poczX;
    y=event->y()-poczY;

    Pixel::drawPixel(x,y,150,100,300,img);
    update();
}

void MainWindow:: mouseReleaseEvent(QMouseEvent *event)
{
    unsigned char *ptr;
    ptr = img->bits();

    int x,y;
    x=event->x()-poczX;
    y=event->y()-poczY;

    Pixel::drawPixel(x,y,150,100,300,img);
    update();
}
