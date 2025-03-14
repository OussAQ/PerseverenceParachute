#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSpinBox * sectorSpin = new QSpinBox();
    sectorSpin->
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

