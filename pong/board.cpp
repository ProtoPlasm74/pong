#include "board.h"




board::board(QWidget *theWindow)
{
    this->setFixedSize(600, 400);
    imageTimeout = new QTimer();
    imageTimeout->setInterval(100);
    connect(imageTimeout,SIGNAL(timeout()),this,SLOT(coordinateUpdate()));
    imageTimeout->start();
    ballImage = new ball(this);
    paddle1 = new Paddle(50,160);
    paddle2 = new Paddle2(this->width() - 70, 160);
    timeIter = 0;
//    p1score = 0;
//    p2score = 0;
//    P1dispSc = new QLabel;
//    P2dispSc = new QLabel;
//    P1dispSc->setGeometry(250, 20, 50, 50);
//    P2dispSc->setGeometry(350, 20, 50, 50);
//    P1dispSc->setText(QString::number(p1score));
//    P2dispSc->setText(QString::number(p2score));
//    P1dispSc->show();
//    P2dispSc->show();
}

void board::paintEvent(QPaintEvent *event)
{
    QPainter visibleWindow(this);
    ballImage->drawImage(visibleWindow);
    paddle1->drawPaddle(&visibleWindow);
    paddle2->drawPaddle(&visibleWindow);
}

void board::resetAndScore(int in)
{
    if (in != 0)
    {
        imageTimeout->setInterval(100);
        timeIter = 0;
        ballImage = new ball(this);
        paddle1->setPosY(160);
        paddle2->setPosY(160);
    }

    if (in == 1)
    {
        p1score++;
    }
    else if (in == -1)
    {
        p2score++;
    }
}

void board::coordinateUpdate()
{
    //bool hitPaddle;
    if(timeIter < 1900)
    {
    timeIter++;
    }
    ballImage->coordinateUpdate();
    ballImage->checkBorder();
    ballImage->checkCollision(paddle1->GetPosX(), paddle1->GetPosY());
    ballImage->checkCollision(paddle2->GetPosX(), paddle2->GetPosY());
    paddle1->UpdatePosition();
    paddle2->UpdatePosition();
    resetAndScore(ballImage->winCheck());
    imageTimeout->setInterval(100 - timeIter/20);
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
