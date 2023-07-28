#ifndef WIN5_H
#define WIN5_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "win6.h"




namespace Ui {
class win5;
}

class win5 : public QDialog
{
    Q_OBJECT

public:
    explicit win5(QWidget *parent = nullptr);
    ~win5();

public:
    QSqlDatabase outdb;
    void connClose3()
    {
        outdb.close();
outdb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen3()
    {
          outdb = QSqlDatabase::addDatabase("QSQLITE");
            outdb.setDatabaseName("E:/final/database/cart.db");


            if(!outdb.open())
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
private slots:
    void on_pushButton_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::win5 *ui;
 win6 *Win6;
};

#endif // WIN5_H
