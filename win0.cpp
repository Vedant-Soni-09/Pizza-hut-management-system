#include "win0.h"
#include "ui_win0.h"

win0::win0(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::win0)
{
    ui->setupUi(this);
    ui->pushButton->setLayoutDirection(Qt::LeftToRight);
}

win0::~win0()
{
    delete ui;
}

void win0::on_pushButton_clicked()
{
    hide();
    Mainwindow = new MainWindow(this);
    Mainwindow -> show();
    Mainwindow->setFixedSize(Mainwindow->size());
}

