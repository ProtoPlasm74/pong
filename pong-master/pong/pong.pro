#-------------------------------------------------
#
# Project created by QtCreator 2017-04-19T11:13:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pong
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    board.cpp \
    paddle.cpp \
    paddle2.cpp

HEADERS  += mainwindow.h \
    ball.h \
    board.h \
    paddle.h \
    paddle2.h

FORMS    += mainwindow.ui
