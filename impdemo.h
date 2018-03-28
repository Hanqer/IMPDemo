#ifndef IMPDEMO_H
#define IMPDEMO_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
namespace Ui {
class IMPDemo;
}

class IMPDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit IMPDemo(QWidget *parent = 0);
    ~IMPDemo();

private:
    Ui::IMPDemo *ui;

    QMenu* menu[10];
      QAction* act[10];
      QMenuBar* menuBar ;
      QStatusBar* status ;
};


#endif // IMPDEMO_H
