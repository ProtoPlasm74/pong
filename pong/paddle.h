#ifndef PADDLE_H
#define PADDLE_H
#include <QKeyEvent>
#include <QPainter>


class Paddle
{
public:
    Paddle();
    Paddle(int posX, int posY);
    void drawPaddle(QPainter* paint);
    int GetPosX();
    int GetPosY();
    void setPosX(int x);
    void setPosY(int y);
    void InputHandler(QKeyEvent *e, bool isPressed);
    void UpdatePosition();
private:
    int posX, posY, frame;
    bool moveUp, moveDown, isMovingUp, isMovingDown;
    int direction, lastDirection; //direction is noted by 0 for Up, 1 for Down, -1 for not moving.

    int paddleRender[10][4] =
    {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
};

#endif // PADDLE_H