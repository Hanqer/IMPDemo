#ifndef IMPDEMO_H
#define IMPDEMO_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>

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
};

#endif // IMPDEMO_H
