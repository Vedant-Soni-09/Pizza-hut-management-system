#include "win6.h"
#include "ui_win6.h"
#include <QMessageBox>
#include <QtSql>
//#include "win2.h"

win6::win6(QWidget *parent) : QDialog(parent),
                              ui(new Ui::win6)
{
    ui->setupUi(this);

    connOpen(); //opening connection the the database
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(Tabledb);

    qry->prepare("select * from Available"); //extracting the whole table from database
    qry->exec();                             //executing the query

    modal->setQuery(*qry); //extracting the data for further operation

    ui->tableView_2->setModel(modal); //setting up extracted value in table view
    qDebug() << (modal->rowCount());  //verifying the row affected throughdebug mode

    //    model= new QSqlTableModel(this);
    //    model->setTable("Available");
    //    model->select();

    //    ui->tableView_2->setModel(model);

    connClose(); //closing the connection to the databse
}

win6::~win6()
{
    delete ui;
}

void win6::on_pushButton_2_clicked()
{
}

void win6::on_A1_clicked()
{

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A1(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A1->setDisabled(true);
        ui->A1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }

    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_pushButton_22_clicked()
{
    connOpen();
    QSqlQuery status;
    status.prepare("Update Available Set Status='AVAILABLE'"); //extracting the whole table from database
    status.exec();

    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(Tabledb);

    qry->prepare("select * from Available"); //extracting the whole table from database
    qry->exec();                             //executing the query

    modal->setQuery(*qry); //extracting the data for further operation

    ui->tableView_2->setModel(modal); //setting up extracted value in table view
    qDebug() << (modal->rowCount());
    connClose();

    ui->A1->setEnabled(true);
    ui->A2->setEnabled(true);
    ui->A3->setEnabled(true);
    ui->A4->setEnabled(true);
    ui->A5->setEnabled(true);
    ui->A6->setEnabled(true);
    ui->B1->setEnabled(true);
    ui->B2->setEnabled(true);
    ui->B3->setEnabled(true);
    ui->B4->setEnabled(true);
    ui->B5->setEnabled(true);
    ui->B6->setEnabled(true);
    ui->C1->setEnabled(true);
    ui->C2->setEnabled(true);
    ui->C3->setEnabled(true);
    ui->C4->setEnabled(true);
    ui->C5->setEnabled(true);
    ui->C6->setEnabled(true);
    ui->PA1->setEnabled(true);
    ui->PA2->setEnabled(true);
    ui->PB1->setEnabled(true);
    ui->PB2->setEnabled(true);
    ui->PC1->setEnabled(true);
    ui->PC2->setEnabled(true);

    ui->A1->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->A2->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->A3->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->A4->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->A5->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->A6->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B1->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B2->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B3->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B4->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B5->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->B6->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C1->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C2->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C3->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C4->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C5->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->C6->setStyleSheet(":enabled {color: white;background-color: rgb(82, 209, 53);border-width: 10px;border-radius: 25px;}");
    ui->PA1->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
    ui->PA2->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
    ui->PB1->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
    ui->PB2->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
    ui->PC1->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
    ui->PC2->setStyleSheet(":enabled {color: white;background-color: rgb(255, 153, 0);border-width: 10px;border-radius: 25px;}");
}

void win6::on_A2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A2(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A2->setDisabled(true);
        ui->A2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_A3_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A3(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A3'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A3->setDisabled(true);
        ui->A3->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_A4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A4(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A4'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A4->setDisabled(true);
        ui->A4->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_A5_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A5(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A5'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A5->setDisabled(true);
        ui->A5->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_A6_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table A6(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='A6'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->A6->setDisabled(true);
        ui->A6->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B1_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B1(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B1->setDisabled(true);
        ui->B1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B2(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B2->setDisabled(true);
        ui->B2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B3_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B3(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B3'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B3->setDisabled(true);
        ui->B3->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B4(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B4'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B4->setDisabled(true);
        ui->B4->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B5_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B5(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B5'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B5->setDisabled(true);
        ui->B5->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_B6_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table B6(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='B6'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->B6->setDisabled(true);
        ui->B6->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C1_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C1(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C1->setDisabled(true);
        ui->C1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C2(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C2->setDisabled(true);
        ui->C2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C3_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C3(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C3'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C3->setDisabled(true);
        ui->C3->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C4_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C4(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C4'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C4->setDisabled(true);
        ui->C4->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C5_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C5(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C5'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C5->setDisabled(true);
        ui->C5->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_C6_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table C6(Regular)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='C6'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->C6->setDisabled(true);
        ui->C6->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PA1_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PA1(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PA1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PA1->setDisabled(true);
        ui->PA1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PA2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PA2(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PA2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PA2->setDisabled(true);
        ui->PA2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PB1_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PB1(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PB1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PB1->setDisabled(true);
        ui->PB1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PB2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PB2(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PB2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PB2->setDisabled(true);
        ui->PB2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PC1_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PC1(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PC1'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PC1->setDisabled(true);
        ui->PC1->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_PC2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Booking", "Do You Want To Book Table PC2(Premium, with extra charges)", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        connOpen();
        QSqlQuery status;
        status.prepare("Update Available Set Status='Booked' where Seat='PC2'"); //extracting the whole table from database
        status.exec();

        QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(Tabledb);

        qry->prepare("select * from Available"); //extracting the whole table from database
        qry->exec();                             //executing the query

        modal->setQuery(*qry); //extracting the data for further operation

        ui->tableView_2->setModel(modal); //setting up extracted value in table view
        qDebug() << (modal->rowCount());
        ui->PC2->setDisabled(true);
        ui->PC2->setStyleSheet(":disabled {color:black;background-color: rgb(80, 81, 82);border-width: 10px;border-radius: 25px;}");
        //closing the connection to the databse
    }
    else
    {
        qDebug() << "Yes was *not* clicked";
    }
    connClose();
}

void win6::on_pushButton_32_clicked()
{
    hide();
    Win7 = new win7(this);
    Win7->show();
}

