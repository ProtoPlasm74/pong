#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "ball.h"

class board:public QWidget
{
    Q_OBJECT

public:
    board(QWidget* theWindow = 0)
    {
        imageTimeout = new QTimer();
        imageTimeout->setInterval(100);
        connect(imageTimeout,SIGNAL(timeout()),this,SLOT(coordinateUpdate()));
        imageTimeout->start();
        ballImage = new ball(this);
    }
    void paintEvent(QPaintEvent *event)
    {
        QPainter visibleWindow(this);
        ballImage->drawImage(visibleWindow);
    }

private:
    QTimer* imageTimeout;
    ball* ballImage;

private slots:
    void coordinateUpdate()
    {
        ballImage->coordinateUpdate();
        ballImage->checkBorder();
        this->update();
    }
};

#endif // BOARD_H
