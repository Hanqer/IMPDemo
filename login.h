#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QMessageBox>
#include <QDebug>
#include "impdemo.h"
#include "registerui.h"
namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();

private:
    Ui::LogIn *ui;
    static bool createConnection();
private slots:
    void loginSlot();
    void registerSlot();

//private:
public:
    IMPDemo imp;
    RegisterUI reg;
};

#endif // LOGIN_H
