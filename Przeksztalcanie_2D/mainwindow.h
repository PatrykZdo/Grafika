#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QGroupBox>
#include <QSlider>
#include <iostream>
#include <QGraphicsScene>
#include <utility>

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QImage *img;
    QImage *Image;

    int image_width;
    int image_height;
    int position_x_start;
    int position_y_start;


    //Buttons
    QPushButton *Reset_Button;
    QPushButton *Exit_Button;


    //Sliders
    QSlider *Transaction_X_Slider;
    QSlider *Transaction_Y_Slider;

    QSlider *Rotation_Slider;

    QSlider *Scaling_Verticaly_Slider;
    QSlider *Scaling_Horizontaly_Slider;

    QSlider *Shearing_Horizontaly_Slider;
    QSlider *Shearing_Verticaly_Slider;


    //Groups
    QGroupBox *Transaction_Group;
    QGroupBox *Rotation_Group;
    QGroupBox *Scaling_Group;
    QGroupBox *Shearing_Group;
    QGroupBox *Buttons_Group;


    int Previous_x;
    int Previous_y;
    float last_Value_Of_shx;
    float last_Value_Of_shy;

    int *Point_Transformation;
    float **Matrix_Transfortmation;
    float **Matrix_Transfortmation_copy;
    float **Matrix_Rotation_copy;
    float **Matrix_Tranzaction_copy;
    float **Matrix_Shearing_copy;



    void clean();
    int *color(int x, int y, QImage *Image);


    float **Transaction(float **Matrix, int x_Vector, int y_Vector);
    float **Rotation(float **Matrix, int kat);
    float **Scaling(float **Matrix, int Sx, int Sy);
    float **Shearing(float **Matrix, float Shx, float Shy);


    float **Matrix_Multiplication_3X3(float **First_Matrix, float Second_Matrix[3][3]);
    int *Matrix_Multiplication_3X1(float **First_Matrix, int *Second_Matrix);
    void Uzupelnianie_x(float **Matrix);

private slots:

    void slot_Reset();
    void Scaling_Slider_Release();
    void Rotation_Slider_Release();
    void Tranzaction_Slider_Release();
    void Shearing_Slider_Release();

    void copy(QImage*, QImage*);
    void paintEvent(QPaintEvent*);

    void value_Change_Transaction_SLider();
    void value_Change_Scaling_Slider();
    void value_Change_Rotation_Slider();
    void values_Change_Shearing_Slider();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *e);
};
#endif // MAINWINDOW_H
