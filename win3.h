#ifndef WIN3_H
#define WIN3_H

#include <QDialog>
#include "win4.h"

namespace Ui {
class win3;
}

class win3 : public QDialog
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
    explicit win3(QWidget *parent = nullptr);
    ~win3();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::win3 *ui;
    win4 *Win4;
};

#endif // WIN3_H
