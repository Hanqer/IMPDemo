#include "impdemo.h"
#include "ui_impdemo.h"

IMPDemo::IMPDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IMPDemo)
{
    ui->setupUi(this);

    // test code
}

IMPDemo::~IMPDemo()
{
    delete ui;
}
