#ifndef WIN1_H
#define WIN1_H


#include <QDialog>
#include "win2.h"
#include "win6.h"

namespace Ui {
class win1;
}

class win1 : public QDialog
{
    Q_OBJECT

public:
    explicit win1(QWidget *parent = nullptr);
    ~win1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::win1 *ui;
    win2 *Win2;
    win6 *Win6;
};

#endif // WIN1_H
