#include "ball.h"
#include "dialog.h"
#include "board.h"

//constructor
ball::ball(QWidget *windowObject):windowObject(windowObject)
{
    //ballImage = new QPixmap("../pong/apple.png");
    coorX = 300;
    coorY = 200;
    displayImage = new QPainter();
    srand(time(NULL));
    trackDirection = rand()%3;
}

//void ball::drawImage(QPainter &paint)
//{
//    paint.drawPixmap(coorX,coorY,50,50,*ballImage);//
//draws the ball onto the board
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
//moves the ball in the direction it is currently travelling
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
//checks the border of the screen. If the ball is on the border, it bounces off of it
void ball::checkBorder()
{
    if(coorX <= 0){
        if(trackDirection == downLeft){
            trackDirection = downRight;
        }else{
            trackDirection = upRight;
        }
//        return 1;
    }else if(coorY <= 0){
        if(trackDirection == upRight){
            trackDirection = downRight;
        }else{
            trackDirection = downLeft;
        }
//        return 0;
    }else if(coorX >= (windowObject->width()-20)){
        if(trackDirection == downRight){
            trackDirection = downLeft;
        }else{
            trackDirection = upLeft;
        }
//        return -1;
    }else if(coorY >= (windowObject->height()-20)){
        if(trackDirection == downLeft){
            trackDirection = upLeft;
        }else{
            trackDirection = upRight;
        }
//        return 0;
    }
}
//checks to see which side the ball is bouncing off of.
//If it is the area behind the paddles, it returns 1 or -1 depending on the side.
int ball::winCheck()
{
    if(coorX <= 0)
    {
        Dialog::on_lcdNumber_overflow();
        board::showDialog();
        return 1;
    }
    else if (coorX >= windowObject->width() - 30)
    {
        Dialog::on_lcdNumber_2_overflow();
        board::showDialog();
        return -1;
    }
    else
    {
        board::showDialog();
        return 0;
    }
}
//this estimates the paddle location based on where the ball is and where it is going next.
//If it finds the top or bottom of the paddle, it will reflect back upon its entry line.
//If it finds the center, it reflects as though it bounced off a wall.
void ball::checkCollision(int paddleX, int paddleY)
{
    int X, Y;

    if(trackDirection == downRight){
        X = coorX + 10;
        Y = coorY + 10;

            if(X <= paddleX + 15 && X >= paddleX)
            {
                if((Y > paddleY && Y < paddleY + 60) || (coorY > paddleY && coorY < paddleY + 60))
                {
                trackDirection = downLeft;
                }
                else if((Y >= paddleY && Y <= paddleY + 10)|| (coorY >= paddleY && coorY <= paddleY + 10))
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
            if((Y > paddleY && Y < paddleY + 60)|| (coorY > paddleY && coorY < paddleY + 60))
            {
            trackDirection = upLeft;
            }
            else if((Y <= paddleY + 65 && Y >= paddleY + 55)|| (coorY <= paddleY + 65 && coorY >= paddleY + 55))
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
            if((Y > paddleY && Y < paddleY + 60)|| (coorY > paddleY && coorY < paddleY + 60))
            {
            trackDirection = downRight;
            }
            else if((Y >= paddleY  && Y<= paddleY + 10) || (coorY >= paddleY && coorY <= paddleY + 10))
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
            if((Y > paddleY && Y < paddleY + 60) || (coorY > paddleY && coorY < paddleY + 60))
            {
            trackDirection = upRight;
            }
            else if((Y <= paddleY + 65 && Y >= paddleY + 55)|| (coorY <= paddleY + 65 && coorY >= paddleY + 55))
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
