#include "paddle2.h"

Paddle2::Paddle2()
{
    posX = 0;
    posY = 0;
    frame = 0;
}

Paddle2::Paddle2(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
    this->frame = 0;
}

void Paddle2::drawPaddle(QPainter *paint)
{

    int rX = posX, rY = posY;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(paddleRender[i][j] == 1)
            {
                paint->drawRect(rX, rY, 10, 50);
            }

            rX += 1;
        }

        rX = posX;
        rY += 1;
    }
}

void Paddle2::InputHandler(QKeyEvent *e, bool isPressed)
{
    if(isPressed)
    {
        switch(e->key())
        {
        case Qt::Key_Up:
            moveUp = true;
            break;
        case Qt::Key_Down:
            moveDown = true;
            break;
        default:
            break;
        }
    }
    else
    {
        switch(e->key())
        {
        case Qt::Key_Up:
            moveUp = false;
            break;
        case Qt::Key_Down:
            moveDown = false;
            break;
        default:
            break;
        }
    }
}

void Paddle2::UpdatePosition()
{
    if(moveUp)
    {
        direction = 0;
        isMovingUp = true;
        isMovingDown = false;
    }
    else if(moveDown)
    {
        direction = 1;
        isMovingUp = false;
        isMovingDown = true;
    }
    else
    {
        //Stop moving
        isMovingUp = false;
        isMovingDown = false;
        direction = -1;
    }

    if((0 == direction) && (posY >= 18) && isMovingUp)
        posY -= 10;
    else if((1 == direction) && ((posY + 45) <= 400) && isMovingDown)
        posY += 10;
    else
        posY = posY;
}

int Paddle2::GetPosX()
{
    return this->posX;
}


int Paddle2::GetPosY()
{
    return this->posY;
}
