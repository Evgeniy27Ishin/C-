#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    values = new QList<QPair<int,QString>>();

    values->append(QPair<int,QString>(-1,"Select item"));
    values->append(QPair<int,QString>(10,"item1(0)"));
    values->append(QPair<int,QString>(11,"item1(1)"));
    values->append(QPair<int,QString>(21,"item1(2)"));
    values->append(QPair<int,QString>(32,"item1(3)"));
    values->append(QPair<int,QString>(44,"item1(4)"));

    model = new QComboBoxModel();
    model->populate(values);
    this->ui->comboBox->setModel(model);

    values->append(QPair<int,QString>(46,"item1(6)"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    model->append(99,"New Item");
}


void MainWindow::on_pushButton_2_clicked()
{
    (*this->values)[4].second = "New row value 4";

    model->update(ui->comboBox->currentIndex(),"New row value");
    model->update(4,"New row value 4");
    qDebug() << (*this->values)[0].first;
    (*this->values)[0].first = -20;
    qDebug() << (*this->values)[0].first;
}


void MainWindow::on_pushButton_3_clicked()
{
    (*this->values).removeAt(0);
    model->deleteRow(0);
}


void MainWindow::on_pushButton_4_clicked()
{
    values->insert(0,QPair<int,QString>(-2,"Pre Select item"));
    QModelIndex item_idx = model->index(0,0);
    emit model->dataChanged(item_idx, item_idx );
    model->insertAt(0, -2,"Pre Select item");
}

