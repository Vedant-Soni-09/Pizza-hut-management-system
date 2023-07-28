#include "win1.h"
#include "ui_win1.h"
#include "win2.h"
#include "win6.h"


win1::win1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win1)
{
    ui->setupUi(this);
}

win1::~win1()
{
    delete ui;
}

void win1::on_pushButton_2_clicked()
{
hide();
    Win2 = new win2(this);
    Win2 -> show();
    Win2->setFixedSize(Win2->size());
}


void win1::on_pushButton_3_clicked()
{
    win1::close();
}


void win1::on_pushButton_clicked()
{

    Win6 = new win6(this);
    Win6 -> show();
    Win6->setFixedSize(Win6->size());
}

