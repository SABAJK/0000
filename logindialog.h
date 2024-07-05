#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

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

private:
    Ui::LogInDialog *ui;
};

#endif // LOGINDIALOG_H
