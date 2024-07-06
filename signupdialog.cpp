#include "signupdialog.h"
#include "ui_signupdialog.h"


SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::on_pushButton_register_clicked()
{
        QString name = ui->lineEdit_name->text();
        QString username = ui->lineEdit_username->text();
        QString phone = ui->lineEdit_phonenumber->text();
        QString address = ui->lineEdit_address->text();
        QString password = ui->lineEdit_password->text();

        SignUp signUp(name, username, phone, address, password);

        if (signUp.saveUser()) {
            QMessageBox::information(this, "Registration Successful", "User registered successfully.");
        } else {
            QMessageBox::warning(this, "Registration Failed", "User registration failed.");
        }
}

