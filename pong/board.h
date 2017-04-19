#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "ball.h"

class board:public QWidget
{
    Q_OBJECT

public:
    board(QWidget* theWindow = 0);
    void paintEvent(QPaintEvent *event);

private:
    QTimer* imageTimeout;
    ball* ballImage;

private slots:
    void coordinateUpdate();
};

#endif // BOARD_H
