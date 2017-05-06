#include "paddle.h"

Paddle::Paddle()
{

}

Paddle::Paddle(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
    this->frame = 0;
}

void Paddle::drawPaddle(QPainter *paint)
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

void Paddle::InputHandler(QKeyEvent *e, bool isPressed)
{
    if(isPressed)
    {
        switch(e->key())
        {
        case Qt::Key_W:
            moveUp = true;
            break;
        case Qt::Key_S:
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
        case Qt::Key_W:
            moveUp = false;
            break;
        case Qt::Key_S:
            moveDown = false;
            break;
        default:
            break;
        }
    }
}

void Paddle::UpdatePosition()
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
        posY -= 15;
    else if((1 == direction) && ((posY + 45) <= 850) && isMovingDown)
        posY += 15;
    else
        posY = posY;
}
