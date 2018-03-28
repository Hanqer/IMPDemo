#include "impdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMPDemo w;
    w.show();

    return a.exec();
}
