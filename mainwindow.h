#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include "parachute.h"
#include "parachutewidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Parachute* parachute;
    ParachuteWidget* parachuteWidget;

    QLineEdit* messageInput;
    QLineEdit* referenceCharInput;
    QSpinBox* sectorsInput;
    QSpinBox* tracksInput;
    QPushButton* color1Button;
    QPushButton* color2Button;
    QCheckBox* randomColorsCheck;

    void setupUI();
    void updateParachute();

private slots:
    void onSettingsChanged();
    void chooseColor1();
    void chooseColor2();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif
