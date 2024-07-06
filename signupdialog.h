#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include "signup.h"
#include <QMessageBox>

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

private slots:
    void on_pushButton_register_clicked();

private:
    Ui::SignupDialog *ui;
};

#endif // SIGNUPDIALOG_H
