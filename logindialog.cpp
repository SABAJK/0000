#include "logindialog.h"
#include "ui_logindialog.h"
#include "loginmanager.h"
#include <QMessageBox>

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    LoginManager loginManager;
    if(loginManager.login(username, password)){
        QMessageBox::information(this, "login", "username and password are correct");
        accept();
    }
    else
    {
        QMessageBox::warning(this,"login", "username or password are not correct");
    }
}

