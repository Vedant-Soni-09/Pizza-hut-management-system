#include "win5.h"
#include "ui_win5.h"
#include "win1.h"
#include "win6.h"

win5::win5(QWidget *parent) : QDialog(parent),
                              ui(new Ui::win5)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(false);

    ui->lineEdit_2->setValidator(new QIntValidator(0, 10000000, this));

    //showing the cart on the ui

    connOpen3();
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(outdb);
    qry->prepare("select * from show");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    qDebug() << (modal->rowCount());

    connClose3();
}

win5::~win5()
{
    delete ui;
}

void win5::on_pushButton_clicked()
{

    //Clearing Cart for next use

    connOpen3();

    QSqlQuery query;
    query.prepare("DELETE FROM show");
    query.exec();
    connClose3();

    QMessageBox::information(this, "Thank You!", "Please Experience Table Booking and visit again!");
}

void win5::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    connOpen2();
    QSqlQuery qry;
    qry.prepare("select * from show where Pizza='" + val + "' or Price='" + val + "'");

    if (qry.exec())
    {
        while (qry.next())
        {
            ui->lineEdit_6->setText(qry.value(0).toString());
            ui->lineEdit_7->setText(qry.value(1).toString());
        }
        connClose2();
    }
    else
    {
        QMessageBox::critical(this, tr("error"), qry.lastError().text());
    }
}

void win5::on_pushButton_2_clicked()
{
    connOpen3();

//        QSqlQuery zero;
//        zero.prepare("select count(*) from show");
//        zero.exec();
//        qDebug() << zero.executedQuery();

//        int z=zero.value(0).toInt();
//        if(z==0){

//        QMessageBox::warning(this,"Cart is Empty","Cart is empty, Please select some item from Menu");
//        }

//        else
//        {
    ui->pushButton_2->setStyleSheet("QPushButton{color: white; background-color: rgb(104, 190, 57); border-width: 10px; border-radius: 25px; }");
    ui->pushButton_2->setText("Confirmed!");

    QSqlQuery query;
    query.prepare("select sum(Price) from show");
    query.exec();

    QString value = "";
    while (query.next())
    {
        value = query.value(0).toString();
    }
    ui->lineEdit->setText(value);

//        }

    connClose3();

}

void win5::on_pushButton_3_clicked()
{
    QString Total = ui->lineEdit->text();
    QString Paid = ui->lineEdit_2->text();
    if (Total == Paid)
    {
        ui->pushButton_3->setStyleSheet("QPushButton{color: white; background-color: rgb(104, 190, 57); border-width: 10px; border-radius: 25px; }");
        ui->pushButton_3->setText("Verified!");
        QMessageBox::information(this, "Payment Done", "Payment Accepted. Please Checkout!");
        ui->pushButton->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this, "Payment Error", "Please pay all the Dues first to Ckeckout!");
    }
}

void win5::on_pushButton_4_clicked()
{
    hide();
    parentWidget()->show();
}

void win5::on_pushButton_5_clicked()
{
    hide();
    Win6 = new win6(this);
    Win6->show();
}

void win5::on_pushButton_6_clicked()
{
    QString Pizza = ui->lineEdit_6->text();
    QString Price = ui->lineEdit_7->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Edit Cart", "Do You Want To Remove selected Item??", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen2();
        QSqlQuery status;
        status.prepare("delete from show where Pizza='" + Pizza + "' and Price=" + Price + " "); //extracting the whole table from database
        status.exec();
        qDebug() << status.executedQuery();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(cartdb);

        qry->prepare("select * from show"); //extracting the whole table from database
        qry->exec();                        //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView->setModel(modal); //setting up extracted value in table view

        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose2();
}
