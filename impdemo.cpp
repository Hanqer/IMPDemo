#include "impdemo.h"
#include "ui_impdemo.h"

IMPDemo::IMPDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IMPDemo)
{
    ui->setupUi(this);
//    QString fileName = QFileDialog::getOpenFileName(
//                   this, tr("open image file"),
//                   "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));
    // test code
    this->resize(400,300);
        this->centralWidget();

        status = new QStatusBar(this);

        menu[0] = new QMenu("文件");
        menu[0]->addAction("编辑");
        menu[0]->addAction("查看");
        menu[0]->addAction("工具");

        act[0] = new QAction("新建",this);
        act[0]->setShortcut(Qt::CTRL | Qt::Key_A );
        act[0]->setStatusTip("这是一个新建菜单");

        act[1] = new QAction("打开",this);
        act[1]->setCheckable(true);

        menu[1] = new QMenu("保存");
        menu[1]->addAction(act[0]);
        menu[1]->addAction(act[1]);

        menu[2] = new QMenu("打印");
        menu[2]->addAction("打印设置");
        menu[2]->addMenu(menu[1]);

        menuBar = new QMenuBar(this);
        menuBar->addMenu(menu[0]);
        menuBar->addMenu(menu[2]);
        menuBar->setGeometry(0,0,this->width(),30);


        menuBar->show();
}

IMPDemo::~IMPDemo()
{
    delete ui;
}
