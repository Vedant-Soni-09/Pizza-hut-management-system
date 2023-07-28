#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connecting Database

    if (!connOpen())
        ui->status->setText("Connection Unsuccessful!");

    else
        ui->status->setText("Connected Successfully!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString Username, Password;
    Username = ui->lineEdit->text();
    Password = ui->lineEdit_2->text();

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from login where Username='" + Username + "' and Password= '" + Password + "'");

    if (qry.exec())
    {
        qDebug() << qry.executedQuery();
        int count = 0;
        while (qry.next())
        {
            count++;
        }

        if (count == 1)
        {
            QMessageBox::information(this, "Login", "username and password is correct");
            hide();
            Win1 = new win1(this);
            Win1->show();
            Win1->setFixedSize(Win1->size());
        }
        if (count > 1)
        {
            QMessageBox::warning(this, "Login", "Duplicate username and password");
        }
        if (count < 1)
        {
            QMessageBox::information(this, "Login", "username and password is not correct");
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString First_Name, Last_Name, Username, Password, ConfirmPassword;
    First_Name = ui->lineEdit_3->text();
    Last_Name = ui->lineEdit_5->text();
    Username = ui->lineEdit_4->text();
    Password = ui->lineEdit_6->text();
    ConfirmPassword = ui->lineEdit_7->text();

    //confirming password
    if (Password != ConfirmPassword)
    {
        QMessageBox::warning(this, "Confirm Password", " Password don't match!! Try Again");
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO login (Username, Password,First_Name, Last_Name) VALUES('" + Username + "','" + Password + "','" + First_Name + "','" + Last_Name + "')");

        if (qry.exec())
        {
            QMessageBox::about(this, "Registration Successful!", "Account Has Been Registered. Continue to Login ");
        }
        else
        {
            QMessageBox::warning(this, "Registration Unsuccesful!", qry.lastError().text());
        }
    }
    //closing database connections

    connClose();
}
