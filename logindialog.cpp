#include "LogInDialog.h"
#include "ui_LogInDialog.h"
#include "ResetPasswordDialog.h"
#include <QMessageBox>

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog),
    client(new Client(this))
{
    ui->setupUi(this);
    connect(client, &Client::loginResponse, this, &LogInDialog::onLoginResponse);
    client->connectToServer("127.0.0.1", 12345); // آدرس IP و پورت سرور را وارد کنید
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
    client->login(username, password);
}

void LogInDialog::on_pushButton_forgetpassword_clicked()
{
    ResetPasswordDialog resetPass;
    resetPass.exec();
}

void LogInDialog::onLoginResponse(const QString &status)
{
    if (status == "success") {
        QMessageBox::information(this, "Login Successful", "User logged in successfully.");
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
