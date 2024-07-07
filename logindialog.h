#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "Client.h"
//#include "signup.h"

namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = nullptr);
    ~LogInDialog();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_forgetpassword_clicked();
    void onLoginResponse(const QString &status);

private:
    Ui::LogInDialog *ui;
    Client *client;
};

#endif // LOGINDIALOG_H
