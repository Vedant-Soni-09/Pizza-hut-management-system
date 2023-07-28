#include "win2.h"
#include "ui_win2.h"
#include "win3.h"
#include "win4.h"

win2::win2(QWidget *parent) : QDialog(parent),
                              ui(new Ui::win2)
{
    ui->setupUi(this);
}

win2::~win2()
{
    delete ui;
}

void win2::on_pushButton_clicked()
{
    hide();
    Win3 = new win3(this);
    Win3->show();
}

void win2::on_pushButton_2_clicked()
{
    hide();
    Win4 = new win4(this);
    Win4->show();
}

void win2::on_pushButton_5_clicked()
{
    hide();
    parentWidget()->show();
}

void win2::on_pushButton_3_clicked()
{
    connOpen2();
    QString cartPizza = "Offer1";
    QString cartPrice = "198";
    QSqlQuery query;
    query.prepare("INSERT INTO show (Pizza, Price) VALUES('" + cartPizza + "','" + cartPrice + "')");

    if (query.exec())
    {
        QMessageBox::information(this, "Congratulations!", "Offer item added to cart");
    }

    else
        QMessageBox::warning(this, "Error", "Manually add to cart or Try Again");

    connClose2();
}

void win2::on_pushButton_4_clicked()
{
    connOpen2();
    QString cartPizza = "Offer2";
    QString cartPrice = "169";
    QSqlQuery query;
    query.prepare("INSERT INTO show (Pizza, Price) VALUES('" + cartPizza + "','" + cartPrice + "')");
    if (query.exec())
    {
        QMessageBox::information(this, "Congratulations!", "Offer item added to cart");
    }

    else
        QMessageBox::warning(this, "Error", "Manually add to cart or Try Again");

    connClose2();
}
