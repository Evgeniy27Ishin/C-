#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString currentTime = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(currentTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}


