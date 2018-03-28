#include "login.h"
#include "ui_login.h"
LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");

    QObject::connect(ui->logInButton,SIGNAL(clicked(bool)),this,SLOT(loginSlot()));
    QObject::connect(ui->registerButton,SIGNAL(clicked(bool)),this,SLOT(registerSlot()));

    //构造函数完成数据库的初始化工作
    if(!createConnection()){
        qDebug()<<"error!";
        return;
    }
    QSqlDatabase db = QSqlDatabase::database("memory");
    QSqlQuery query(db);


    query.exec("create table user( name varchar(30), "
               "password varchar(30))");
    query.exec("insert into user values('orzrocky','orzrocky')");
    if(!query.exec()){
        qDebug()<<query.lastError();
    }


}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::loginSlot()
{
    bool logInSuccessfulFlag = false;
    QString usrName = ui->usrNameLineEdit->text();
    QString usrPassWord = ui->usrPasswordLineEdit->text();
    //关于对密码加密的操作暂时不考虑

    QSqlDatabase db = QSqlDatabase::database("memory");
    QSqlQuery query(db);
    query.exec("select * from user");
    while(query.next())
    {
        if(usrName == query.value(0).toString() && usrPassWord == query.value(1).toString())
        {
            imp.show();
            logInSuccessfulFlag = true;
            this->close();
            break;
        }
    }

    if(!logInSuccessfulFlag)
        QMessageBox::warning(this,"warning","usr name or password error!\npleasr try again!");
}

void LogIn::registerSlot()
{
    reg.show();
}

bool LogIn::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","memory");
    db.setDatabaseName("usr.db");
    if(!db.open()){
        qDebug()<<"db open failed!";
        return false;
    }
    return true;
}
