#ifndef BALL_H
#define BALL_H
#include <Qtimer>
#include <QPixmap>
#include <Qpainter>
#include <QWidget>

class ball:public QWidget
{
    Q_OBJECT

public:
    ball(QWidget *windowObject = 0):windowObject(windowObject)
    {
        ballImage = new QPixmap("../pong/apple.png");
        coorX = 0;
        coorY = 0;
        displayImage = new QPainter();
        trackDirection = downRight;
    }
    void drawImage(QPainter& paint)
    {
        paint.drawPixmap(coorX,coorY,50,50,*ballImage);
    }
    void coordinateUpdate()
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
    void checkBorder()
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
    enum {upRight, downRight, upLeft, downLeft};

private:
    int trackDirection;
    int coorX, coorY;
    QPixmap* ballImage;
    QPainter* displayImage;
    QWidget* windowObject;
};

#endif // BALL_H
