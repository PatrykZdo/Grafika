#include "mainwindow.h"

#include <QGroupBox>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <cmath>
#include "Pixel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Przekształacanie zdjęć");

    resize(800,700);

    this->image_width = 600;
    this->image_height = 600;
    this->position_x_start = 25;
    this->position_y_start = 25;

    img = new QImage(image_width,image_height,QImage::Format_RGB32);
    clean();
    Image = new QImage("C:\\Users\\2patr\\OneDrive\\Dokumenty\\Przeksztalcanie_2D\\Pingwin.jpg");
    copy(Image,img);
    update();

    //Matrix of point after transformation
    Point_Transformation = new int[3];
    Point_Transformation[2] = 1;


    //Creating Transformation Matrix
    Matrix_Transfortmation = new float*[3];
    for (int i=0;i<3;i++){
        Matrix_Transfortmation [i] = new float[3];
        for(int j =0;j<3;j++){
            Matrix_Transfortmation[i][j]=0;
        }
    }


    last_Value_Of_shx=0;
    last_Value_Of_shy=0;


    //Transition

    Transaction_Group = new QGroupBox("Transaction",this);
    Transaction_Group->setGeometry(QRect(position_x_start + image_width + position_x_start, position_y_start, 800 - image_width - 2*position_x_start, position_y_start + 50));

    Transaction_X_Slider = new QSlider(Qt::Horizontal,this);
    Transaction_Y_Slider = new QSlider(Qt::Horizontal,this);

    // values of Trasaction Sliders
    Transaction_X_Slider -> setMinimum( -600);
    Transaction_X_Slider -> setMaximum( 600);
    Transaction_X_Slider -> setValue(0);

    Transaction_Y_Slider -> setMinimum( -600 );
    Transaction_Y_Slider -> setMaximum( 600);
    Transaction_Y_Slider -> setValue(0);



    QVBoxLayout *Transaction_Layout= new QVBoxLayout;

    Transaction_Layout -> addWidget(Transaction_X_Slider);
    Transaction_Layout -> addWidget(Transaction_Y_Slider);

    Transaction_Group -> setLayout(Transaction_Layout);

    connect(Transaction_X_Slider,SIGNAL(valueChanged(int)),this,SLOT(value_Change_Transaction_SLider()));
    connect(Transaction_Y_Slider,SIGNAL(valueChanged(int)),this,SLOT(value_Change_Transaction_SLider()));



    //Rotation

    Rotation_Group = new QGroupBox("Rotation",this);
    Rotation_Group -> setGeometry(QRect(position_x_start + image_width + position_x_start, 2*position_y_start + 50, 800 - image_width - 2*position_x_start, position_y_start + 25));

    Rotation_Slider = new QSlider(Qt::Horizontal,this);
    Rotation_Slider -> setMaximum(360);
    Rotation_Slider -> setMinimum(0);
    Rotation_Slider -> setValue(0);

    QVBoxLayout *Rotation_Layout = new QVBoxLayout;

    Rotation_Layout -> addWidget(Rotation_Slider);

    Rotation_Group -> setLayout(Rotation_Layout);

    connect(Rotation_Slider,SIGNAL(valueChanged(int)),this,SLOT(value_Change_Rotation_Slider()));
    connect(Rotation_Slider,SIGNAL(sliderReleased()),this,SLOT(Rotation_Slider_Release()));



    //Scaling

    Scaling_Group = new QGroupBox("Scaling",this);
    Scaling_Group -> setGeometry(QRect(position_x_start + image_width + position_x_start, 3*position_y_start + 75, 800 - image_width - 2*position_x_start, position_y_start +50));

    Scaling_Horizontaly_Slider = new QSlider(Qt::Horizontal,this);
    Scaling_Verticaly_Slider = new QSlider(Qt::Horizontal,this);

    QVBoxLayout *Scaling_Layout = new QVBoxLayout;

    Scaling_Layout -> addWidget(Scaling_Horizontaly_Slider);
    Scaling_Layout -> addWidget(Scaling_Verticaly_Slider);

    Scaling_Group -> setLayout(Scaling_Layout);

    Scaling_Horizontaly_Slider -> setMinimum(1);
    Scaling_Horizontaly_Slider -> setMaximum(20);
    Scaling_Horizontaly_Slider -> setValue(10);

    Scaling_Verticaly_Slider -> setMinimum(1);
    Scaling_Verticaly_Slider -> setMaximum(20);
    Scaling_Verticaly_Slider -> setValue(10);

    connect(Scaling_Verticaly_Slider,SIGNAL(valueChanged(int)),this,SLOT(value_Change_Scaling_Slider()));
    connect(Scaling_Horizontaly_Slider,SIGNAL(valueChanged(int)),this,SLOT(value_Change_Scaling_Slider()));

    connect(Scaling_Verticaly_Slider,SIGNAL(sliderReleased()),this,SLOT(Scaling_Slider_Release()));
    connect(Scaling_Horizontaly_Slider,SIGNAL(sliderReleased()),this,SLOT(Scaling_Slider_Release()));


    //Shearing

    Shearing_Group = new QGroupBox("Shearing",this);
    Shearing_Group -> setGeometry(QRect(position_x_start + image_width + position_x_start, 4*position_y_start + 125, 800 - image_width - 2*position_x_start, position_y_start + 50));

    Shearing_Horizontaly_Slider = new QSlider(Qt::Horizontal,this);
    Shearing_Verticaly_Slider = new QSlider(Qt::Horizontal,this);

    QVBoxLayout *Shearing_Layout = new QVBoxLayout;

    Shearing_Layout -> addWidget(Shearing_Horizontaly_Slider);
    Shearing_Layout -> addWidget(Shearing_Verticaly_Slider);

    Shearing_Group -> setLayout(Shearing_Layout);

    Shearing_Horizontaly_Slider->setMinimum(-25);
    Shearing_Horizontaly_Slider->setMaximum(25);
    Shearing_Horizontaly_Slider->setValue(0);

    Shearing_Verticaly_Slider->setMinimum(-25);
    Shearing_Verticaly_Slider->setMaximum(25);
    Shearing_Verticaly_Slider->setValue(0);

    connect(Shearing_Horizontaly_Slider,SIGNAL(valueChanged(int)),this,SLOT(values_Change_Shearing_Slider()));
    connect(Shearing_Verticaly_Slider,SIGNAL(valueChanged(int)),this,SLOT(values_Change_Shearing_Slider()));

    connect(Shearing_Horizontaly_Slider,SIGNAL(sliderReleased()),this,SLOT(Shearing_Slider_Release()));
    connect(Shearing_Verticaly_Slider,SIGNAL(sliderReleased()),this,SLOT(Shearing_Slider_Release()));


    // Buttons (Reset , Exit)

    Reset_Button = new QPushButton("Reset", this);
    Reset_Button -> setGeometry(2*position_x_start + image_width, 5*position_y_start + 175, 60, 25);

    Exit_Button = new QPushButton("Exit", this);
    Exit_Button -> setGeometry(2*position_x_start + image_width + 70, 5*position_y_start + 175, 60, 25);

    connect(Exit_Button,SIGNAL(clicked()),this,SLOT(close()));
    connect(Reset_Button,SIGNAL(clicked()),this,SLOT(slot_Reset()));

}

MainWindow::~MainWindow()
{
delete img;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(position_x_start,position_y_start,*img);
}

void MainWindow::clean(){
    unsigned char *ptr;
                ptr = img->bits();

                int i,j;
                for(i=0; i<image_width; i++)
                {
                    for(j=0; j<image_height; j++)
                    {
                        ptr[image_width*4*i + 4*j]= 255; // Skladowa BLUE
                        ptr[image_width*4*i + 4*j + 1] = 255; // Skladowa GREEN
                        ptr[image_width*4*i + 4*j + 2] = 255; // Skladowa RED
                    }
                }
        update();
}

void MainWindow::copy(QImage* img,QImage* bg){
    int x=img->width();
    int y=img->height();

    int background_width = bg->width();
    for(int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            bg->bits()[background_width*4*j + 4*i]=img->bits()[x*4*j + 4*i];
            bg->bits()[background_width*4*j + 4*i+1]=img->bits()[x*4*j + 4*i+1];   //funkcja kopjujaca "obrazy"
            bg->bits()[background_width*4*j + 4*i+2]=img->bits()[x*4*j + 4*i+2];
        }
    }
}


void MainWindow::Tranzaction_Slider_Release(){
    Transaction_X_Slider -> setValue(0);
    Transaction_Y_Slider -> setValue(0);
}

void MainWindow::Scaling_Slider_Release(){
    Matrix_Transfortmation = Matrix_Transfortmation_copy;
    Scaling_Horizontaly_Slider ->setValue(10);
    Scaling_Verticaly_Slider -> setValue(10);
}


void MainWindow::Rotation_Slider_Release(){
    Matrix_Transfortmation = Matrix_Rotation_copy;
}

void MainWindow::Shearing_Slider_Release(){
   Matrix_Transfortmation = Matrix_Shearing_copy;
   Shearing_Horizontaly_Slider -> setValue(0);
   Shearing_Verticaly_Slider ->setValue(0);
}




int *MainWindow::color(int x, int y, QImage *Image){
    int *colors = new int[3];
    unsigned char *ptr;
    int szer = Image -> width();
    ptr = Image -> bits();

    colors[0] = ptr[szer*4*y + 4*x];
    colors[1] = ptr[szer*4*y + 4*x + 1];
    colors[2] = ptr[szer*4*y + 4*x + 2];

    return colors;

}


float **MainWindow::Matrix_Multiplication_3X3(float **First_Matrix, float Second_Matrix[3][3]){
    float **Result_Matrix = new float*[3];
    for(int i=0;i<3;i++){
        Result_Matrix[i] = new float[3];
        for(int j=0;j<3;j++){
            Result_Matrix[i][j]=0;
        }
    }

    for (int i = 0; i < 3; i++ ){
        for (int j=0; j<3; j++){
            for(int k=0;k<3;k++){

                Result_Matrix[i][j]= Result_Matrix[i][j] + (First_Matrix[i][k]*Second_Matrix[k][j]);
            }
        }

    }
    return Result_Matrix;
}


int *MainWindow::Matrix_Multiplication_3X1(float **First_Matrix, int *Second_Matrix){
    int *Point_Transformation = new int[3];
    Point_Transformation[0]=0;
    Point_Transformation[1]=0;
    Point_Transformation[2]=0;

    for (int i = 0; i < 3; i++ ){
            for(int j=0;j<3;j++){
                Point_Transformation[i] += First_Matrix[i][j] * Second_Matrix[j];
            }
    }

    return Point_Transformation;
}

void MainWindow::Uzupelnianie_x(float ** Matrix){
    int *tab= new int[3];
    tab[2]=1;
    int *tablicaPoprzedniego = new int[3];
    tablicaPoprzedniego[2]=1;
    int *col = new int[3];


    for (int i=1; i<=Image->width() -1; i++){
        for(int j=1; j<= Image->height()-1 ; j++){
            tablicaPoprzedniego[0]=i - 1;
            tablicaPoprzedniego[1]=j - 1;
            tablicaPoprzedniego = Matrix_Multiplication_3X1(Matrix,tablicaPoprzedniego);
            col[0]=55;
            col[1]=55;
            col[2]=55;
            //Pixel::drawPixel(tablicaPoprzedniego[0],j,col,img);

            tab[0]=i;
            tab[1]=j;
            tab = Matrix_Multiplication_3X1(Matrix,tab);
            col[0]=155;
            col[1]=10;
            col[2]=255;
            //Pixel::drawPixel(tab[0],j,col,img);
            for(int k=tablicaPoprzedniego[0];k<=tab[0];k++){
                for(int l = tablicaPoprzedniego[1]; l<=tab[1];l++){
                  Pixel::drawPixel(k,l,color(i,j,Image),img);
                }
            }
        }
    }
    update();
}


float **MainWindow::Transaction(float **Matrix, int x_Vector, int y_Vector){
    float Matrix_Transaction[3][3]={{1,0,(float)x_Vector},{0,1,(float)y_Vector},{0,0,1}};

    if(Matrix[2][2] == 0){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Matrix[i][j] = Matrix_Transaction[i][j];
            }
        }
    }
    else{
        Matrix = Matrix_Multiplication_3X3(Matrix,Matrix_Transaction);
    }

    return Matrix;
}

float **MainWindow::Scaling(float **Matrix, int Sx, int Sy){
    if(Sx == 0 || Sy == 0)return Matrix;
    float ScalX = (float)Sx / 10.0;
    float ScalY = (float)Sy / 10.0;


    float Matrix_Scaling[3][3]={{ScalX,0,0},{0,ScalY,0},{0,0,1}};


    if(Matrix[2][2] == 0){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Matrix[i][j] = Matrix_Scaling[i][j];
            }
        }
    }
    else{
        Matrix = Matrix_Multiplication_3X3(Matrix,Matrix_Scaling);
    }
    return Matrix;
}

float **MainWindow::Rotation(float **Matrix,int kat){
    float kat1 =(float)kat *M_PI / 180;
    float Matrix_Rotation[3][3]={{cos((float)kat1), - sin((float)kat1),0},{sin((float)kat1),cos((float)kat1),0},{0,0,1}};
    if(Matrix[2][2] == 0){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Matrix[i][j] = Matrix_Rotation[i][j];
            }
        }
    }
    else{
        Matrix = Matrix_Multiplication_3X3(Matrix,Matrix_Rotation);
    }
    return Matrix;
}


float **MainWindow::Shearing(float **Matrix,float Shx, float Shy){
    float hx = (float)Shx/100.0;
    float hy = (float)Shy/100.0;
    float Matrix_Shearing[3][3] = { {1.0, hx, 0.0}, {hy, 1.0, 0.0}, {0.0, 0.0, 1.0} };
    if(Matrix[2][2] == 0){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Matrix[i][j] = Matrix_Shearing[i][j];
            }
        }
    }
    else{
        Matrix = Matrix_Multiplication_3X3(Matrix,Matrix_Shearing);
    }
    return Matrix;
}





void MainWindow::slot_Reset(){
    Transaction_X_Slider -> setValue(0);
    Transaction_Y_Slider -> setValue(0);

    Scaling_Horizontaly_Slider -> setValue(10);
    Scaling_Verticaly_Slider -> setValue(10);

    Rotation_Slider -> setValue(0);

    Shearing_Horizontaly_Slider -> setValue(0);
    Shearing_Verticaly_Slider -> setValue(0);

    clean();
    copy(Image,img);
    update();
    for (int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            Matrix_Transfortmation[i][j]=0;
        }
    }
}


void MainWindow::value_Change_Transaction_SLider(){
    int *colors;

    clean();
    Matrix_Transfortmation[0][2] -= Previous_x;
    Matrix_Transfortmation[1][2] -= Previous_y;
    Matrix_Transfortmation = Transaction(Matrix_Transfortmation, Transaction_X_Slider -> value(), Transaction_Y_Slider -> value());
    for (int i=0; i< Image->width(); i++){
        for(int j=0; j< Image->height(); j++){
            Point_Transformation[0]=i;
            Point_Transformation[1]=j;
            Point_Transformation = Matrix_Multiplication_3X1(Matrix_Transfortmation,Point_Transformation);
            colors = color(i,j,Image);
            Pixel::drawPixel(Point_Transformation[0], Point_Transformation[1], colors, img);
            update();
        }
    }
    Uzupelnianie_x(Matrix_Transfortmation);
    Previous_x = Matrix_Transfortmation[0][2];
    Previous_y = Matrix_Transfortmation[1][2];
    delete[] colors;
}

void MainWindow::value_Change_Scaling_Slider(){
    int *colors;

    clean();
    Matrix_Transfortmation_copy = Scaling(Matrix_Transfortmation, Scaling_Horizontaly_Slider -> value(), Scaling_Verticaly_Slider -> value());
    for (int i=0; i< Image->width(); i++){
        for(int j=0; j< Image->height(); j++){
            Point_Transformation[0]=i;
            Point_Transformation[1]=j;
            Point_Transformation = Matrix_Multiplication_3X1(Matrix_Transfortmation_copy,Point_Transformation);
            colors = color(i,j,Image);
            Pixel::drawPixel(Point_Transformation[0], Point_Transformation[1], colors, img);

            update();
        }
    }
    Uzupelnianie_x(Matrix_Transfortmation_copy);
    delete[] colors;
}

void MainWindow::value_Change_Rotation_Slider(){
    int *colors;

    clean();
    Matrix_Rotation_copy = Rotation(Matrix_Transfortmation, Rotation_Slider -> value());
    for (int i=0; i< Image->width(); i++){
        for(int j=0; j< Image->height(); j++){
            Point_Transformation[0]=i;
            Point_Transformation[1]=j;
            Point_Transformation = Matrix_Multiplication_3X1(Matrix_Rotation_copy,Point_Transformation);
            colors = color(i,j,Image);
            Pixel::drawPixel(Point_Transformation[0], Point_Transformation[1], colors, img);
            update();
        }
    }
    Uzupelnianie_x(Matrix_Rotation_copy);

    delete[] colors;
}


void MainWindow::values_Change_Shearing_Slider(){
    int *colors;

    clean();

    Matrix_Shearing_copy = Shearing(Matrix_Transfortmation,Shearing_Horizontaly_Slider->value() ,Shearing_Verticaly_Slider->value());
    for (int i=0; i< Image->width(); i++){
        for(int j=0; j< Image->height(); j++){
            Point_Transformation[0]=i;
            Point_Transformation[1]=j;
            Point_Transformation = Matrix_Multiplication_3X1(Matrix_Shearing_copy,Point_Transformation);
            colors = color(i,j,Image);
            Pixel::drawPixel(Point_Transformation[0], Point_Transformation[1], colors, img);

            update();
        }
    }
    Uzupelnianie_x(Matrix_Shearing_copy);
    delete[] colors;
}

void MainWindow::mousePressEvent(QMouseEvent *event){


}

void MainWindow::mouseReleaseEvent(QMouseEvent *e){
}
