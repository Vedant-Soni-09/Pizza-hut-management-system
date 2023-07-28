#ifndef WIN7_H
#define WIN7_H

#include <QDialog>

namespace Ui {
class win7;
}

class win7 : public QDialog
{
    Q_OBJECT

public:
    explicit win7(QWidget *parent = nullptr);
    ~win7();

private:
    Ui::win7 *ui;
};

#endif // WIN7_H
