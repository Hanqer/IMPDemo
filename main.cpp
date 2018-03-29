#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogIn login;
    login.imp.show();

    return a.exec();
}
