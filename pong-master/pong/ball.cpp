#include "ball.h"




ball::ball(QWidget *windowObject):windowObject(windowObject)
{
    //ballImage = new QPixmap("../pong/apple.png");
    coorX = 0;
    coorY = 0;
    displayImage = new QPainter();
    trackDirection = downRight;
}

//void ball::drawImage(QPainter &paint)
//{
//    paint.drawPixmap(coorX,coorY,50,50,*ballImage);//
void ball::drawImage(QPainter &paint)
{

    int rX = coorX, rY = coorY;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(ballRender[i][j] == 1)
            {
                paint.drawRect(rX, rY, 5, 5);
            }

            rX += 1;
        }

        rX = coorX;
        rY += 1;
    }
}
//}

void ball::coordinateUpdate()
{
    if(trackDirection == downRight){
        coorX += 10;
        coorY += 10;
    }else if(trackDirection == upRight){
        coorX += 10;
        coorY -= 10;
    }else if(trackDirection == downLeft){
        coorX -= 10;
        coorY += 10;
    }else{
        coorX -= 10;
        coorY -= 10;
    }
}

void ball::checkBorder()
{
    if(coorX <= 0){
        if(trackDirection == downLeft){
            trackDirection = downRight;
        }else{
            trackDirection = upRight;
        }
    }else if(coorY <= 0){
        if(trackDirection == upRight){
            trackDirection = downRight;
        }else{
            trackDirection = downLeft;
        }
    }else if(coorX >= (windowObject->width()-50)){
        if(trackDirection == downRight){
            trackDirection = downLeft;
        }else{
            trackDirection = upLeft;
        }
    }else if(coorY >= (windowObject->height()-50)){
        if(trackDirection == downLeft){
            trackDirection = upLeft;
        }else{
            trackDirection = upRight;
        }
    }
}

void ball::checkCollision(int paddleX, int paddleY)
{
    int X, Y;

    if(trackDirection == downRight){
        X = coorX + 10;
        Y = coorY + 10;

            if(X <= paddleX + 15 && X >= paddleX)
            {
                if((Y > paddleY && Y < paddleY + 55))
                {
                trackDirection = downLeft;
                }
                else if((Y >= paddleY && Y<= paddleY + 10))
                {
                trackDirection = upLeft;
                }
            }
            else
            {
                //track direction remains unchanged
            }
    }else if(trackDirection == upRight){
        X = coorX + 10;
        Y = coorY - 10;
        if(X <= paddleX + 15 && X >= paddleX)
        {
            if((Y > paddleY && Y < paddleY + 60))
            {
            trackDirection = upLeft;
            }
            else if(Y <= paddleY + 65 && Y <= paddleY + 55)
            {
            trackDirection = downLeft;
            }
        }
            else
            {
                //direction does not change
            }
    }else if(trackDirection == downLeft){
        X = coorX - 10;
        Y = coorY + 10;
        if(X <= paddleX + 15 && X >= paddleX)
        {
            if((Y > paddleY && Y < paddleY + 55))
            {
            trackDirection = downRight;
            }
            else if((Y >= paddleY - 5 && Y<= paddleY + 5))
            {
            trackDirection = upRight;
            }
        }
        else
        {
            //direction does not change
        }
    }else{
        X = coorX - 10;
        Y = coorY - 10;
        if(X <= paddleX + 15 && X >= paddleX)
        {
            if((Y > paddleY && Y < paddleY + 55))
            {
            trackDirection = upRight;
            }
            else if((Y <= paddleY + 65 && Y <= paddleY + 55))
            {
            trackDirection = downRight;
            }
        }
        else
        {
             //direction does not change
        }
    }
}
