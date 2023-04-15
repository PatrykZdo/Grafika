#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QGroupBox>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QSlider>
#include <QLCDNumber>
#include <QCheckBox>
#include <vector>
#include <math.h>
#include <Pixel.h>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    friend class Pixel;

    //Pola przechowujace obrazek
    QImage *img;

    //Przyciski
    QPushButton *RGB_Button;
    QPushButton *HSV_Button;

    //Slidery   RGB
    QSlider *sliderR;
    QSlider *sliderG;
    QSlider *sliderB;

    //Slidery   HSV
    QSlider *sliderH;
    QSlider *sliderS;
    QSlider *sliderV;

    //Grupy
    QGroupBox *grupaOpcje;
    QGroupBox *grupaRGB;
    QGroupBox *grupaHSV;

    //Pola przechowujace szerokosc i wysokosc rysunku
    int szer;
    int wys;
    int poczX;
    int poczY;

    //colory
    int colorB;
    int colorG;
    int colorR;

    //chars
    char pointer;
    char pointer_HSV;


    //Deklaracja funkcji
    void clean(QImage*);
    void copy(QImage*, QImage*);
    void colorMixerRGB(char,int);
    void colorMixerHSV(char,float);
    void convert(float,float,float,int,int);


    //Deklaracja slotow
private slots:
    //RGB Slots
    void RGB_colorPicker();

    void sliderR_pressed();
    void sliderG_pressed();
    void sliderB_pressed();

    void sliderR_changed();
    void sliderG_changed();
    void sliderB_changed();

    //HSV Slots
    void HSV_colorPicker();

    void sliderH_pressed();
    void sliderS_pressed();
    void sliderV_pressed();

    void sliderH_changed();
    void sliderS_changed();
    void sliderV_changed();

    //MouseEvents
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent*);

};
#endif // MAINWINDOW_H
