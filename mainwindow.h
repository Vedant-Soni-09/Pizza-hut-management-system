#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "win1.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("E:/final/database/pizza.db");


        if(!mydb.open()){
            qDebug()<<("Connection Unsuccessful!");
            return false;
        }

         else
            qDebug()<<("Connected Successfully!");
        return true;
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

//    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    win1 *Win1;

};

#endif // MAINWINDOW_H
