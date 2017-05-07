#include "board.h"



board::board(QWidget *theWindow)
{
    imageTimeout = new QTimer();
    imageTimeout->setInterval(100);
    connect(imageTimeout,SIGNAL(timeout()),this,SLOT(coordinateUpdate()));
    imageTimeout->start();
    ballImage = new ball(this);
    paddle1 = new Paddle(10,10);
    paddle2 = new Paddle(this->width() - 10, 10);
}

void board::paintEvent(QPaintEvent *event)
{
    QPainter visibleWindow(this);
    ballImage->drawImage(visibleWindow);
    paddle1->drawPaddle(&visibleWindow);
    paddle2->drawPaddle(&visibleWindow);
}

void board::coordinateUpdate()
{
    bool hitPaddle;
    ballImage->coordinateUpdate();
    hitPaddle = ballImage->checkCollision(paddle1->GetPosX(), paddle1->GetPosY());
    hitPaddle = ballImage->checkCollision(paddle2->GetPosX(), paddle2->GetPosY());
    ballImage->checkBorder(hitPaddle);
    paddle1->UpdatePosition();
    paddle2->UpdatePosition();
    this->update();
}
void board::keyPressEvent(QKeyEvent *event)
{
    paddle1->InputHandler(event, true);
    paddle2->InputHandler(event, true);
    event->accept();
}

void board::keyReleaseEvent(QKeyEvent *event)
{
    paddle1->InputHandler(event, false);
    paddle2->InputHandler(event, false);
    event->accept();
}
