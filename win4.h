#ifndef WIN4_H
#define WIN4_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "win5.h"

namespace Ui {
class win4;
}

class win4 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase ratedb;
    void connClose()
    {
        ratedb.close();
//        ratedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
          ratedb = QSqlDatabase::addDatabase("QSQLITE");
            ratedb.setDatabaseName("E:/final/database/rate.db");


            if(!ratedb.open())
            {
                qDebug()<<("Connection Unsuccessful!");
            return false;
            }

             else
            {
                qDebug()<<("Connected Successfully!");
                return true;
            }

    }

public:
    QSqlDatabase cartdb;
    void connClose2()
    {
        cartdb.close();
 cartdb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen2()
    {
          cartdb = QSqlDatabase::addDatabase("QSQLITE");
            cartdb.setDatabaseName("E:/final/database/cart.db");


            if(!cartdb.open())
            {
                qDebug()<<("Connection Unsuccessful!");
            return false;
            }

             else
            {
                qDebug()<<("Connected Successfully!");
                return true;
            }

    }
public:
    explicit win4(QWidget *parent = nullptr);
    ~win4();

private slots:
    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::win4 *ui;
    win5 *Win5;

};

#endif // WIN4_H
