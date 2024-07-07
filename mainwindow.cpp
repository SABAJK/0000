#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "signupdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    LogInDialog logInDialog;
    logInDialog.exec();
}



void MainWindow::on_pushButton_signup_clicked()
{
    SignupDialog SignUpDialog;
    SignUpDialog.exec();
}

