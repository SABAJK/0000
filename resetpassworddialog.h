#ifndef RESETPASSWORDDIALOG_H
#define RESETPASSWORDDIALOG_H

#include <QDialog>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "signupdialog.h"

namespace Ui {
class ResetPasswordDialog;
}

class ResetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResetPasswordDialog(QWidget *parent = nullptr);
    ~ResetPasswordDialog();
    bool isPasswordStrong(const QString &password);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ResetPasswordDialog *ui;
};

#endif // RESETPASSWORDDIALOG_H
