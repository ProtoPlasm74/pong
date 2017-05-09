#include "dialog.h"
#include "ui_dialog.h"
#include "board.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lcdNumber_overflow()
{
    ui->lcdNumber->display(ui->lcdNumber->value()+1);
}

void Dialog::on_lcdNumber_2_overflow()
{
    ui->lcdNumber->display(ui->lcdNumber->value()+1);
}

void Dialog::on_pushButton_2_clicked()
{
    board = new board(NULL);
    board.show();
}

void Dialog::on_pushButton_clicked()
{
    this->close();
}
