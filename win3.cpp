#include "win3.h"
#include "ui_win3.h"
#include "win4.h"

win3::win3(QWidget *parent) : QDialog(parent),
                              ui(new Ui::win3)
{
    ui->setupUi(this);
}

win3::~win3()
{
    delete ui;
}

void win3::on_pushButton_5_clicked()
{
    hide();
    Win4 = new win4(this);
    Win4->show();
}

void win3::on_pushButton_7_clicked()
{
    hide();
    parentWidget()->show();
}

void win3::on_pushButton_clicked()
{
    connOpen2();
    QString cartPizza = "TopS1";
    QString cartPrice = "269";
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

void win3::on_pushButton_2_clicked()
{
    connOpen2();
    QString cartPizza = "TopS2";
    QString cartPrice = "269";
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

void win3::on_pushButton_3_clicked()
{
    connOpen2();
    QString cartPizza = "TopS3";
    QString cartPrice = "359";
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

void win3::on_pushButton_4_clicked()
{
    connOpen2();
    QString cartPizza = "TopS3";
    QString cartPrice = "359";
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
