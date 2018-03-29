#ifndef IMPDEMO_H
#define IMPDEMO_H

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QAction>
#include <QLabel>
#include <QPixmap>
#include <QImage>

namespace Ui {
class IMPDemo;
}

class IMPDemo : public QWidget
{
    Q_OBJECT

public:
    explicit IMPDemo(QWidget *parent = 0);
    ~IMPDemo();

private:
    Ui::IMPDemo *ui;
    QMenu* menu[10];
    //暂时不采用action指针
//    QAction* act[10];
    QMenuBar* menuBar ;
    QStatusBar* status ;

    QImage image;
public slots:
//    void trigerMenu(QAction* act);
     void openFileActionSlot();
};

#endif // IMPDEMO_H
