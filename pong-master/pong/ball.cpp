#include "ball.h"




ball::ball(QWidget *windowObject):windowObject(windowObject)
{
    ballImage = new QPixmap("../pong/apple.png");
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
        coorX += 15;
        coorY += 15;
    }else if(trackDirection == upRight){
        coorX += 15;
        coorY -= 15;
    }else if(trackDirection == downLeft){
        coorX -= 15;
        coorY += 15;
    }else{
        coorX -= 15;
        coorY -= 15;
    }
}

void ball::checkBorder(bool hitPaddle)
{
    if(hitPaddle == true)
    {
        if(trackDirection == downLeft){
            trackDirection = downRight;
        }else{
            trackDirection = upRight;
        }
        //--------------------------
        if(trackDirection == upRight){
            trackDirection = downRight;
        }else{
            trackDirection = downLeft;
        }
        //--------------------------
        if(trackDirection == downRight){
            trackDirection = downLeft;
        }else{
            trackDirection = upLeft;
        }
        //--------------------------
        if(trackDirection == downLeft){
            trackDirection = upLeft;
        }else{
            trackDirection = upRight;
        }
        //--------------------------
    }
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

bool ball::checkCollision(int paddleX, int paddleY)
{
    if(ballRender[paddleY][paddleX] == 1)
        return true;
    else
        return false;
}
