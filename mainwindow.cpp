#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>
#include "parachute.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _parachute = new parachute();
    QSpinBox * sectorSpin = new QSpinBox(this);
    sectorSpin->setRange(0,50);
    sectorSpin->setGeometry(30,30,80,50);
    sectorSpin->setSingleStep(1);
    sectorSpin->setEnabled(true);
    sectorSpin->setStyleSheet("");
    connect(sectorSpin,SIGNAL(valueChanged(int)),this,SLOT(updateNbSectors(int)));
    ui->setupUi(this);
}

void MainWindow::updateNbSectors(int nbSectors){
    _parachute->setSectors(nbSectors);
    std::cout<<_parachute->getSectors()<<std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

