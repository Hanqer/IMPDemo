#include "registerui.h"
#include "ui_registerui.h"

RegisterUI::RegisterUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterUI)
{
    ui->setupUi(this);

    this->setWindowTitle("register");

    QObject::connect(ui->registerButton,SIGNAL(clicked(bool)),this,SLOT(registerSlot()));
}

RegisterUI::~RegisterUI()
{
    delete ui;
}

void RegisterUI::registerSlot()
{
    QString usrName = ui->usrNameLineEdit->text();
    QString usrPassWord = ui->usrNameLineEdit->text();
    QString usrPassWordAgain = ui->usrPassWordAgainLineEdit->text();

    bool ok = true;
    if(usrName.length()<8||usrName.length()>15){
        QMessageBox::warning(this,"warning","8-15 please");
        ok = false;
    }
    if(usrPassWord.length()<8||usrPassWord.length()>15){
        QMessageBox::warning(this,"warning","8-15 please");
        ok = false;
    }
    if(usrPassWordAgain.length()<8||usrPassWordAgain.length()>15){
        QMessageBox::warning(this,"warning","8-15 please");
        ok = false;
    }

    if(usrPassWord!=usrPassWordAgain){
        QMessageBox::warning(this,"warning","密码输入不一致！");
        ok = false;
    }

    if(ok)
    {
        QSqlDatabase db = QSqlDatabase::database("memory");
        QSqlQuery query(db);
        query.prepare("INSERT INTO user (name, password) "
                      "VALUES (:name, :password)");
        query.bindValue(":name", usrName);
        query.bindValue(":password", usrPassWord);
        query.exec();
        QMessageBox::information(this,"","successful!");
        this->close();

    }
}
