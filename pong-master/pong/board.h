#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "ball.h"
#include "paddle.h"
#include "paddle2.h"

class board:public QWidget
{
    Q_OBJECT

public:
    board(QWidget* theWindow = 0);
    void paintEvent(QPaintEvent *event);

private:
    QTimer* imageTimeout;
    ball* ballImage;
    Paddle* paddle1;
    Paddle2* paddle2;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void coordinateUpdate();
};

#endif // BOARD_H
