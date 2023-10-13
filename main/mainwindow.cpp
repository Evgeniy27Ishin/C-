#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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


void MainWindow::on_pushButton_clicked()
{
    QMessageBox msg;
    if (ui->lineEdit->text().length() == 0) {
        msg.setText("Введите первое число");
        msg.exec();
        ui->lineEdit->setFocus();
        return;
    }
    if (ui->lineEdit_3->text().length() == 0) {
        msg.setText("Введите второе число");
        msg.exec();
        ui->lineEdit_3->setFocus();
        return;
    }

    float a = ui->lineEdit->text().toFloat();
    float b = ui->lineEdit_3->text().toFloat();
    float c;

    QString act = ui->comboBox->currentText();
    if (act == "+") {
        c = a + b;
    }
    else if (act == "-") {
        c = a - b;
    }
    else if (act == "*") {
        c = a * b;
    }
    else if (act == "/") {
        c = a / b;
    }

    msg.setText(QString::number(c));
    msg.exec();
}

