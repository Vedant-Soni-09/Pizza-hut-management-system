#include "win7.h"
#include "ui_win7.h"

win7::win7(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win7)
{
    ui->setupUi(this);
}

win7::~win7()
{
    delete ui;
}
