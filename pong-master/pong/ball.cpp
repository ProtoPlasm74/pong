#include "ball.h"




ball::ball(QWidget *windowObject):windowObject(windowObject)
{
    ballImage = new QPixmap("../pong/apple.png");
    coorX = 0;
    coorY = 0;
    displayImage = new QPainter();
    trackDirection = downRight;
}

void ball::drawImage(QPainter &paint)
{
    paint.drawPixmap(coorX,coorY,50,50,*ballImage);//
}

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
