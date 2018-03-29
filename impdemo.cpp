#include "impdemo.h"
#include "ui_impdemo.h"

IMPDemo::IMPDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMPDemo)
{
    ui->setupUi(this);

    this->setFixedSize(1000,600);
    status = new QStatusBar(this);
    ui->functionGroup->setFixedSize(100,578);
    ui->menuGroup->setFixedSize(768,100);
    ui->stay->setFixedSize(100,578);

    QAction *openFileAction = new QAction("打开",this);
    openFileAction->setShortcut(Qt::CTRL | Qt::Key_O);
    menu[0] = new QMenu("文件");
    menu[0]->addAction(openFileAction);


    menuBar = new QMenuBar(this);
    menuBar->addMenu(menu[0]);
    menuBar->setGeometry(0,0,this->width(),30);


    QObject::connect(openFileAction,SIGNAL(triggered(bool)),this,SLOT(openFileActionSlot()));
//    QObject::connect(menuBar,SIGNAL(triggered(QAction*)),this,SLOT(trigerMenu(QAction*)));

}

IMPDemo::~IMPDemo()
{
    delete ui;
}

//void IMPDemo::trigerMenu(QAction* act)
//{
//    if(act->text() == "打开")
//    {

//    }

//    else {
//        qDebug()<<"error";
//    }


//}


void IMPDemo::openFileActionSlot()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,tr("open image file"),
                "./",tr("Image files(*.bmp,*.jpg,*.png,*.pbm,*.pgm,*.jpeg);;All files(*.*)"));

    image.load(fileName);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setFixedSize(image.size());
}
