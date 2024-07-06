#include "LogInDialog.h"
#include "ui_LogInDialog.h"
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

    if (SignUp::validateUser(username, password)) {
        QMessageBox::information(this, "Login Successful", "User logged in successfully.");
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
void LogInDialog::on_pushButton_forgetpassword_clicked(){
    ResetPasswordDialog resetPass;
    resetPass.exec();
}
