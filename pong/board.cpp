#include "board.h"


board::board(QWidget *theWindow)
{
    imageTimeout = new QTimer();
    imageTimeout->setInterval(100);
    connect(imageTimeout,SIGNAL(timeout()),this,SLOT(coordinateUpdate()));
    imageTimeout->start();
    ballImage = new ball(this);
}

void board::paintEvent(QPaintEvent *event)
{
    QPainter visibleWindow(this);
    ballImage->drawImage(visibleWindow);
}

void board::coordinateUpdate()
{
    ballImage->coordinateUpdate();
    ballImage->checkBorder();
    this->update();
}
