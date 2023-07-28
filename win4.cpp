#include "win4.h"

#include "ui_win4.h"
#include "win5.h"

win4::win4(QWidget *parent) : QDialog(parent),
                              ui(new Ui::win4)
{
    ui->setupUi(this);

    //connecting Database

    //opening connection
    if (!connOpen())
    {
        ui->label_4->setText("Connection Unsuccessful!"); //showing connection was unsuccessful through a label if databse was not opend
    }
    else
    {
        ui->label_4->setText("Connected Successfully!"); //showing connection was successful through a label
    }
}

win4::~win4()
{
    delete ui;
}

void win4::on_pushButton_3_clicked()
{

    connOpen(); //opening connection the the database
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(ratedb);

    qry->prepare("select * from list"); //extracting the whole table from database
    qry->exec();                        //executing the query

    modal->setQuery(*qry); //extracting the data for further operation

    ui->tableView->setModel(modal);  //setting up extracted value in table view
    qDebug() << (modal->rowCount()); //verifying the row affected throughdebug mode

    connClose(); //closing the connection to the databse
}

void win4::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString(); //extracting the value from the table in model to usable string form

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from list where Pizza='" + val + "' or Type='" + val + "'or Crust='" + val + "' or Price='" + val + "'");

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->lineEdit->setText(qry.value(0).toString());
            ui->lineEdit_2->setText(qry.value(1).toString());
            ui->lineEdit_3->setText(qry.value(2).toString());
            ui->lineEdit_4->setText(qry.value(3).toString());
        }
        connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("error"), qry.lastError().text());
    }
}

void win4::on_pushButton_2_clicked()
{

    //extracting the text shown on line edit for further operations
    QString cartPizza = ui->lineEdit->text();
    QString cartPrice = ui->lineEdit_4->text();
    //opening the connection to the database cart
    connOpen2();

    //Adding shown pizza and price into cart list
    QSqlQuery query;
    query.prepare("INSERT INTO show (Pizza, Price) VALUES('" + cartPizza + "','" + cartPrice + "')");
    query.exec();

    //showing items in cart simultaneously on table view
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(cartdb);
    qry->prepare("select * from show");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_2->setModel(modal);
    qDebug() << (modal->rowCount());

    //closing the connection
    connClose2();
}

void win4::on_pushButton_clicked()
{
    hide();
    Win5 = new win5(this);
    Win5->show();
}

void win4::on_pushButton_4_clicked()
{
    hide();
    parentWidget()->show();
}
