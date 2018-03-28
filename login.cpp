#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::loginSlot()
{

}

void LogIn::registerSlot()
{

}
