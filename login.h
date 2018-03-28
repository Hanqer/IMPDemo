#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <impdemo.h>
#include <QSql>
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

private slots:
    void loginSlot();
    void registerSlot();

private:
    IMPDemo imp;
};

#endif // LOGIN_H
