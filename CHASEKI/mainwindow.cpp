#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clock = new Clock(this);
    clock->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_alarm()
{
    QMessageBox msg;
    msg.setText("Время вышло:");
    msg.exec();
}

void MainWindow::btn_start_click()
{
    clock->start();
}
void MainWindow::btn_stop_click()
{
    clock->stop();
}
void MainWindow::btn_reset_click()
{
    clock->reset();
}
