#ifndef REGISTERUI_H
#define REGISTERUI_H

#include <QDialog>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QMessageBox>
#include <QDebug>

namespace Ui {
class RegisterUI;
}

class RegisterUI : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterUI(QWidget *parent = 0);
    ~RegisterUI();

private:
    Ui::RegisterUI *ui;

private slots:
    void registerSlot();
};

#endif // REGISTERUI_H
