#ifndef WIN6_H
#define WIN6_H
#include <QtSql>
#include <QSqlDatabase>

#include <QDialog>
#include "win7.h"

namespace Ui {
class win6;
}

class win6 : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase Tabledb;
    void connClose()
    {
        Tabledb.close();
//        ratedb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
          Tabledb = QSqlDatabase::addDatabase("QSQLITE");
            Tabledb.setDatabaseName("E:/final/database/Table.db");


            if(!Tabledb.open())
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
    explicit win6(QWidget *parent = nullptr);
    ~win6();

private slots:
//    QSqlTableModel *model;
    void on_pushButton_2_clicked();

    void on_A1_clicked();

    void on_pushButton_22_clicked();

    void on_A2_clicked();

    void on_A3_clicked();

    void on_A4_clicked();

    void on_A5_clicked();

    void on_A6_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_B4_clicked();

    void on_B5_clicked();

    void on_B6_clicked();

    void on_C1_clicked();

    void on_C2_clicked();

    void on_C3_clicked();

    void on_C4_clicked();

    void on_C5_clicked();

    void on_C6_clicked();

    void on_PA1_clicked();

    void on_PA2_clicked();

    void on_PB1_clicked();

    void on_PB2_clicked();

    void on_PC1_clicked();

    void on_PC2_clicked();

    void on_pushButton_32_clicked();

private:
    Ui::win6 *ui;
   win7 *Win7;
};

#endif // WIN6_H
