#include "mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    parachute = new Parachute();
    setupUI();
}

MainWindow::~MainWindow() {
    delete parachute;
}

void MainWindow::setupUI() {
    QWidget* centralWidget = new QWidget(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);

    // Panneau de contrôle
    QVBoxLayout* controlLayout = new QVBoxLayout();

    // Groupe Message
    QGroupBox* messageGroup = new QGroupBox("Message");
    QVBoxLayout* messageLayout = new QVBoxLayout();
    messageInput = new QLineEdit();
    referenceCharInput = new QLineEdit("@");
    referenceCharInput->setMaxLength(1);
    messageLayout->addWidget(new QLabel("Message:"));
    messageLayout->addWidget(messageInput);
    messageLayout->addWidget(new QLabel("Caractère de référence:"));
    messageLayout->addWidget(referenceCharInput);
    messageGroup->setLayout(messageLayout);
    controlLayout->addWidget(messageGroup);

    // Groupe Paramètres
    QGroupBox* settingsGroup = new QGroupBox("Paramètres");
    QGridLayout* settingsLayout = new QGridLayout();
    sectorsInput = new QSpinBox();
    sectorsInput->setRange(7, 100);
    sectorsInput->setValue(21);
    tracksInput = new QSpinBox();
    tracksInput->setRange(1, 20);
    tracksInput->setValue(5);

    color1Button = new QPushButton("Couleur 0");
    color2Button = new QPushButton("Couleur 1");

    settingsLayout->addWidget(new QLabel("Secteurs:"), 0, 0);
    settingsLayout->addWidget(sectorsInput, 0, 1);
    settingsLayout->addWidget(new QLabel("Pistes:"), 1, 0);
    settingsLayout->addWidget(tracksInput, 1, 1);
    settingsLayout->addWidget(color1Button, 2, 0);
    settingsLayout->addWidget(color2Button, 2, 1);

    settingsGroup->setLayout(settingsLayout);
    controlLayout->addWidget(settingsGroup);

    // Options avancées
    QGroupBox* optionsGroup = new QGroupBox("Options");
    QVBoxLayout* optionsLayout = new QVBoxLayout();
    randomColorsCheck = new QCheckBox("Couleurs aléatoires");
    optionsLayout->addWidget(randomColorsCheck);
    optionsGroup->setLayout(optionsLayout);
    controlLayout->addWidget(optionsGroup);

    // Zone de dessin
    parachuteWidget = new ParachuteWidget();
    parachuteWidget->setParachute(parachute);

    // Layout final
    mainLayout->addLayout(controlLayout);
    mainLayout->addWidget(parachuteWidget);
    setCentralWidget(centralWidget);

    // Connexions
    connect(messageInput, &QLineEdit::textChanged, this, &MainWindow::onSettingsChanged);
    connect(referenceCharInput, &QLineEdit::textChanged, this, &MainWindow::onSettingsChanged);
    connect(sectorsInput, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onSettingsChanged);
    connect(tracksInput, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onSettingsChanged);
    connect(color1Button, &QPushButton::clicked, this, &MainWindow::chooseColor1);
    connect(color2Button, &QPushButton::clicked, this, &MainWindow::chooseColor2);
    connect(randomColorsCheck, &QCheckBox::stateChanged, this, &MainWindow::onSettingsChanged);
}

void MainWindow::onSettingsChanged() {
    ParachuteSettings settings;
    settings.sectors = sectorsInput->value();
    settings.tracks = tracksInput->value();
    settings.referenceChar = referenceCharInput->text().isEmpty() ? '@' : referenceCharInput->text().at(0);
    settings.useRandomColors = randomColorsCheck->isChecked();

    parachute->setSettings(settings);
    parachute->setMessage(messageInput->text());
    parachuteWidget->update();
}

void MainWindow::chooseColor1() {
    QColor color = QColorDialog::getColor(parachute->getSettings().color1, this);
    if (color.isValid()) {
        ParachuteSettings settings = parachute->getSettings();
        settings.color1 = color;
        parachute->setSettings(settings);
        parachuteWidget->update();
    }
}

void MainWindow::chooseColor2() {
    QColor color = QColorDialog::getColor(parachute->getSettings().color2, this);
    if (color.isValid()) {
        ParachuteSettings settings = parachute->getSettings();
        settings.color2 = color;
        parachute->setSettings(settings);
        parachuteWidget->update();
    }
}
