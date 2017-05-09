#ifndef BALL_H
#define BALL_H
#include <Qtimer>
#include <QPixmap>
#include <Qpainter>
#include <QWidget>
#include <random>
#include <time.h>
//This class is used for ball logic and functions
//Joshua Bowman
//Zach Morgan
class ball:public QWidget
{
    Q_OBJECT

public:
    ball(QWidget *windowObject = 0);
    void drawImage(QPainter& paint);
    void coordinateUpdate();
    void checkBorder();
    int winCheck();
    void checkCollision(int paddleX, int paddleY);
    enum {upRight, downRight, upLeft, downLeft};

private:
    int trackDirection;
    int coorX, coorY;
    //QPixmap* ballImage;
    QPainter* displayImage;
    QWidget* windowObject;

    int ballRender[4][4] =
    {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
};

#endif // BALL_H
