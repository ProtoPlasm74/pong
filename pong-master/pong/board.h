#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include "ball.h"
#include "paddle.h"
#include "paddle2.h"
//This class is used for display and interconnection functions
//Joshua Bowman
//Zach Morgan
class board:public QWidget
{
    Q_OBJECT

public:
    board(QWidget* theWindow = 0);
    void paintEvent(QPaintEvent *event);
    void resetAndScore(int in);
    void showDialog();

private:
    QTimer* imageTimeout;
    QLabel* P1dispSc, *P2dispSc;
    ball* ballImage;
    Paddle* paddle1;
    Paddle2* paddle2;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int timeIter, p1score, p2score;

private slots:
    void coordinateUpdate();
};

#endif // BOARD_H
