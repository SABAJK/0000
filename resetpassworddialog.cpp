#include "resetpassworddialog.h"
#include "ui_resetpassworddialog.h"
#include "signupdialog.h"

ResetPasswordDialog::ResetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResetPasswordDialog)
{
    ui->setupUi(this);
}

ResetPasswordDialog::~ResetPasswordDialog()
{
    delete ui;
}

void ResetPasswordDialog::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString phone = ui->lineEdit_phonenumber->text();
    QString newPassword = ui->lineEdit_newpassword->text();
    if (!username.isEmpty() && !phone.isEmpty() && !newPassword.isEmpty())
       {

               QString filePath = "D:/users.json";
               QFile file(filePath);

               if (file.exists() && file.open(QIODevice::ReadOnly))
               {
                   QByteArray jsonData = file.readAll();
                   file.close();

                   QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
                   QJsonObject jsonObject = jsonDoc.object();
                   QString storedPhone = jsonObject["phone"].toString();

                   if (jsonObject.contains(username))
                   {
                       if(storedPhone == phone){
                           if(!isPasswordStrong(newPassword)){
                               QMessageBox::warning(this, "Weak password", "Please enter a stronger password at least one capital");
                           }
                           else{
                               QJsonObject userObject = jsonObject[username].toObject();
                               userObject["password"] = newPassword;
                               jsonObject[username] = userObject;

                               if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                               {
                                   file.write(QJsonDocument(jsonObject).toJson());
                                   file.close();
                                   QMessageBox::information(this, "Password Reset Successful\n", "Your password has been reset.");
                               }

                           }
                       }
                       else{
                           QMessageBox::warning(this, "Phone number does not match", "Please enter a match number.");
                       }


                   }
                   else{
                       QMessageBox::warning(this, "Error", "User not found.");
                   }
               }
               else
               {
                   QMessageBox::warning(this, "Error", "Could not open file for reading.");
               }
           }


       else
       {
           QMessageBox::warning(this, "Error", "Please fill all fields.");
       }
}

bool ResetPasswordDialog::isPasswordStrong(const QString &password)
{
    QRegularExpression regExp("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#\\$%\\^&\\*])[A-Za-z\\d!@#\\$%\\^&\\*]{8,}$");
    return regExp.match(password).hasMatch();
}

