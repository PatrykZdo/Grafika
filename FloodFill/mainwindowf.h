#ifndef MAINWINDOWF_H
#define MAINWINDOWF_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>
#include <QGroupBox>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowF; }
QT_END_NAMESPACE

class MainWindowF : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowF(QWidget *parent = nullptr);
    ~MainWindowF();

private:
    QImage *img;
    QImage *bg;

    QPushButton *linia_przycisk;
    QPushButton *kolo_przycisk;
    QPushButton *clean_przycisk;
    QPushButton *fill_przycisk;

     QGroupBox *grupa;

    int szer;
    int wys;
    int posx;
    int posy;

    int startX;
    int startY;
    int endX;
    int endY;

    int colorR;
    int colorG;
    int colorB;

    char pointer;
    int *colors;
    stack<pair<int,int>> pixels;


    //Funkcje
    int *color(int, int);
    void copy(QImage *,QImage *);
    void fill(int,int,int,int,int);

private slots:

    void slot_linia();
    void slot_kolo();
    void slot_fill();
    void clean();

    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOWF_H
