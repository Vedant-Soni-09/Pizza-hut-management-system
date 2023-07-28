#ifndef WIN0_H
#define WIN0_H

#include <QMainWindow>
#include <mainwindow.h>

namespace Ui {
class win0;
}

class win0 : public QMainWindow
{
    Q_OBJECT

public:
    explicit win0(QWidget *parent = nullptr);
    ~win0();

private slots:
    void on_pushButton_clicked();

private:
    Ui::win0 *ui;
    MainWindow *Mainwindow;
};

#endif // WIN0_H
