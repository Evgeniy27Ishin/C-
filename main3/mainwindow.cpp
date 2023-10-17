#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    second = 0;  //начинаем с нуля
    timer = new QTimer(this); //создаем таймер
    timer->setInterval(100); //интервал 1 секунда
    //соединяем сигнал таймера с нашим слотом
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    timer->start();
}

void MainWindow::on_timer() {
    ui->lcdNumber->display(second);
    if (ui->checkBox->checkState() == 2) {
        second--;
    }
    else {
    second++;
    }
}
