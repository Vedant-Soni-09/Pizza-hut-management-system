#ifndef WIN2_H
#define WIN2_H

#include <QDialog>
#include "win3.h"
#include "win4.h"


namespace Ui {
class win2;
}

class win2 : public QDialog
{
    Q_OBJECT
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
    explicit win2(QWidget *parent = nullptr);
    ~win2();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::win2 *ui;
    win3 *Win3;
    win4 *Win4;
};

#endif // WIN2_H
