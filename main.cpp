#include "win0.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    win0 w;
    w.show();
    w.setFixedSize(w.size());

    return a.exec();
}
