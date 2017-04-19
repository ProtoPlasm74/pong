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
    ball(QWidget *windowObject = 0);
    void drawImage(QPainter& paint);
    void coordinateUpdate();
    void checkBorder();
    enum {upRight, downRight, upLeft, downLeft};

private:
    int trackDirection;
    int coorX, coorY;
    QPixmap* ballImage;
    QPainter* displayImage;
    QWidget* windowObject;
};

#endif // BALL_H
