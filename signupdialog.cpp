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
        QString email = ui->lineEdit_email->text();
        QString password = ui->lineEdit_password->text();

        if (!isEmailValid(email)) {
                QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
                return;
            }
        else{
            if (!isPhoneValid(phone)) {
                QMessageBox::warning(this, "Invalid Phone Number", "Please enter a valid phone number.");
                return;
            }else{
                if(!isPasswordStrong(password)){
                    QMessageBox::warning(this, "Weak password", "Please enter a stronger password at least one capital");
                }else{
                    SignUp signUp(name, username, phone, email, password);

                    if (signUp.saveUser()) {
                        QMessageBox::information(this, "Registration Successful", "User registered successfully.");
                    } else {
                        QMessageBox::warning(this, "Registration Failed", "User registration failed.");
                    }
                }
            }

        }



}

bool SignupDialog::isEmailValid(const QString &email)
{
    QRegularExpression emailRegex(R"((^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}$))");
    return emailRegex.match(email).hasMatch();
}

bool SignupDialog::isPhoneValid(const QString &phone)
{
    QRegularExpression phoneRegex(R"(^\+?[0-9]{10,15}$)"); // شماره تلفن باید شامل 10 تا 15 رقم باشد و می‌تواند با "+" شروع شود.
    return phoneRegex.match(phone).hasMatch();
}
bool SignupDialog::isPasswordStrong(const QString &password)
{
    QRegularExpression regExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#\\$%\\^&\\*])[A-Za-z\\d!@#\\$%\\^&\\*]{8,}$");
    return regExp.match(password).hasMatch();
}

