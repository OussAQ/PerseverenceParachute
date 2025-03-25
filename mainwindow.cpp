#include "mainwindow.h"
#include <QColorDialog>
#include <QScreen>
#include <QGuiApplication>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QStatusBar>
#include <QTime>

// Implémentation de HistoryWindow
HistoryWindow::HistoryWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Historique des bits");
    
    historyText = new QTextEdit(this);
    historyText->setReadOnly(true);
    historyText->setFont(QFont("Monospace"));
    historyText->setStyleSheet("QTextEdit { background-color: white; }");
    
    setCentralWidget(historyText);
    resize(400, 300);
}

void HistoryWindow::updateHistory(const QString &text) {
    QString history;
    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text[i];
        Message msg(QString(currentChar).toStdString().c_str());
        msg.setReferenceChar('@');
        
        std::vector<bool> bits = msg.getBitsForChar(0);
        
        QString line = QString("Caractère '%1' (ASCII-7: %2) : ")
                          .arg(currentChar)
                          .arg((int)(currentChar.toLatin1() - '@'));
        
        for (bool bit : bits) {
            line += bit ? "1" : "0";
        }
        
        history += line + "\n";
    }
    historyText->setText(history);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Initialiser le générateur de nombres aléatoires avec l'horloge système
    srand(QTime::currentTime().msecsSinceStartOfDay());
    
    parachute = new Parachute();
    historyWindow = new HistoryWindow();
    
    setupUI();
    setupMenus();
    
    // Positionner la fenêtre d'historique à droite de la fenêtre principale
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    
    // Définir la position de la fenêtre principale
    int mainX = (screenGeometry.width() - 800) / 2;
    int mainY = (screenGeometry.height() - 600) / 2;
    setGeometry(mainX, mainY, 800, 600);
    
    // Positionner la fenêtre d'historique
    historyWindow->setGeometry(mainX + 820, mainY, 400, 600);
    historyWindow->show();
}

MainWindow::~MainWindow() {
    delete parachute;
    delete historyWindow;
}

void MainWindow::setupUI() {
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

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

    // Configuration des secteurs avec Slider et SpinBox
    QHBoxLayout* sectorsLayout = new QHBoxLayout();
    sectorsInput = new QSpinBox();
    sectorsInput->setRange(7, 100);
    sectorsInput->setValue(21);
    
    sectorsSlider = new QSlider(Qt::Horizontal);
    sectorsSlider->setRange(7, 100);
    sectorsSlider->setValue(21);
    sectorsSlider->setTickPosition(QSlider::TicksBelow);
    sectorsSlider->setTickInterval(10);

    sectorsLayout->addWidget(sectorsInput);
    sectorsLayout->addWidget(sectorsSlider);

    // Configuration des pistes avec Slider et SpinBox
    QHBoxLayout* tracksLayout = new QHBoxLayout();
    tracksInput = new QSpinBox();
    tracksInput->setRange(1, 20);
    tracksInput->setValue(5);

    tracksSlider = new QSlider(Qt::Horizontal);
    tracksSlider->setRange(1, 20);
    tracksSlider->setValue(5);
    tracksSlider->setTickPosition(QSlider::TicksBelow);
    tracksSlider->setTickInterval(2);

    tracksLayout->addWidget(tracksInput);
    tracksLayout->addWidget(tracksSlider);

    settingsLayout->addWidget(new QLabel("Secteurs:"), 0, 0);
    settingsLayout->addLayout(sectorsLayout, 0, 1);
    settingsLayout->addWidget(new QLabel("Pistes:"), 1, 0);
    settingsLayout->addLayout(tracksLayout, 1, 1);

    settingsGroup->setLayout(settingsLayout);
    controlLayout->addWidget(settingsGroup);

    // Options avancées
    QGroupBox* optionsGroup = new QGroupBox("Options");
    QVBoxLayout* optionsLayout = new QVBoxLayout();
    
    // Ajout des boutons de couleur
    QHBoxLayout* colorButtonsLayout = new QHBoxLayout();
    QPushButton* color1Button = new QPushButton("Couleur 1");
    QPushButton* color2Button = new QPushButton("Couleur 2");
    QPushButton* randomColorsButton = new QPushButton("Générer couleurs aléatoires");
    QPushButton* resetColorsButton = new QPushButton("Réinitialiser les couleurs");
    colorButtonsLayout->addWidget(color1Button);
    colorButtonsLayout->addWidget(color2Button);
    
    optionsLayout->addLayout(colorButtonsLayout);
    optionsLayout->addWidget(randomColorsButton);
    optionsLayout->addWidget(resetColorsButton);
    optionsGroup->setLayout(optionsLayout);
    controlLayout->addWidget(optionsGroup);

    // Zone de visualisation
    QHBoxLayout* viewLayout = new QHBoxLayout();
    
    // Vue parachute
    parachuteWidget = new ParachuteWidget();
    parachuteWidget->setParachute(parachute);

    // Vue binaire
    binaryView = new BinaryView();
    
    viewLayout->addWidget(parachuteWidget);
    viewLayout->addWidget(binaryView);

    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(viewLayout);
    setCentralWidget(centralWidget);

    // Connexions
    connect(messageInput, &QLineEdit::textChanged, this, &MainWindow::onMessageChanged);
    connect(referenceCharInput, &QLineEdit::textChanged, this, &MainWindow::onReferenceCharChanged);
    connect(sectorsInput, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onSectorsSpinBoxChanged);
    connect(sectorsSlider, &QSlider::valueChanged, this, &MainWindow::onSectorsSliderChanged);
    connect(tracksInput, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::onTracksSpinBoxChanged);
    connect(tracksSlider, &QSlider::valueChanged, this, &MainWindow::onTracksSliderChanged);
    connect(randomColorsButton, &QPushButton::clicked, this, &MainWindow::generateRandomColors);
    connect(resetColorsButton, &QPushButton::clicked, this, &MainWindow::resetColors);

    // Ajouter les connexions pour les boutons de couleur
    connect(color1Button, &QPushButton::clicked, this, [this]() {
        QColor color = QColorDialog::getColor(parachute->getSettings().color1, this);
        if (color.isValid()) {
            ParachuteSettings settings = parachute->getSettings();
            settings.color1 = color;
            parachute->setSettings(settings);
            updateViews();
        }
    });

    connect(color2Button, &QPushButton::clicked, this, [this]() {
        QColor color = QColorDialog::getColor(parachute->getSettings().color2, this);
        if (color.isValid()) {
            ParachuteSettings settings = parachute->getSettings();
            settings.color2 = color;
            parachute->setSettings(settings);
            updateViews();
        }
    });
}

void MainWindow::onMessageChanged(const QString &text) {
    historyWindow->updateHistory(text);
    updateParachute();
}

void MainWindow::onReferenceCharChanged() {
    updateParachute();
}

void MainWindow::onSectorsSpinBoxChanged(int value) {
    if (sectorsSlider->value() != value) {
        sectorsSlider->setValue(value);
        updateParachute();
    }
}

void MainWindow::onSectorsSliderChanged(int value) {
    if (sectorsInput->value() != value) {
        sectorsInput->setValue(value);
        updateParachute();
    }
}

void MainWindow::onTracksSpinBoxChanged(int value) {
    if (tracksSlider->value() != value) {
        tracksSlider->setValue(value);
        updateParachute();
    }
}

void MainWindow::onTracksSliderChanged(int value) {
    if (tracksInput->value() != value) {
        tracksInput->setValue(value);
        updateParachute();
    }
}

void MainWindow::generateRandomColors() {
    ParachuteSettings settings = parachute->getSettings();
    
    // Générer deux couleurs aléatoires indépendantes
    settings.color1 = QColor::fromHsv(rand() % 360,
                                    128 + rand() % 128,  // Saturation entre 128 et 255
                                    128 + rand() % 128); // Luminosité entre 128 et 255
    
    settings.color2 = QColor::fromHsv(rand() % 360,
                                    128 + rand() % 128,  // Saturation entre 128 et 255
                                    128 + rand() % 128); // Luminosité entre 128 et 255
    
    parachute->setSettings(settings);
    updateViews();
}

void MainWindow::resetColors() {
    ParachuteSettings settings = parachute->getSettings();
    
    // Réinitialiser aux couleurs par défaut (blanc et rouge)
    settings.color1 = Qt::white;
    settings.color2 = Qt::red;
    
    parachute->setSettings(settings);
    updateViews();
}

void MainWindow::updateParachute() {
    ParachuteSettings settings;
    settings.sectors = sectorsInput->value();
    settings.tracks = tracksInput->value();
    settings.referenceChar = referenceCharInput->text().isEmpty() ? '@' : referenceCharInput->text().at(0).toLatin1();
    
    // Conserver les couleurs actuelles
    ParachuteSettings currentSettings = parachute->getSettings();
    settings.color1 = currentSettings.color1;
    settings.color2 = currentSettings.color2;

    parachute->setSettings(settings);
    parachute->setMessage(messageInput->text());
    
    updateViews();
}

void MainWindow::updateViews() {
    // Mettre à jour la vue parachute
    parachuteWidget->update();
    
    // Mettre à jour la vue binaire
    binaryView->setMessage(messageInput->text(), 
                          referenceCharInput->text().isEmpty() ? '@' : referenceCharInput->text().at(0).toLatin1());
    
    // Mettre à jour les couleurs de la vue binaire
    ParachuteSettings settings = parachute->getSettings();
    binaryView->setColors(settings.color1, settings.color2);
}

void MainWindow::setupMenus() {
    // Menu Fichier
    fileMenu = menuBar()->addMenu("&Fichier");
    
    newAction = new QAction("&Nouveau", this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip("Créer un nouveau parachute");
    connect(newAction, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAction);

    openAction = new QAction("&Ouvrir...", this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip("Ouvrir un fichier existant");
    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    fileMenu->addAction(openAction);

    saveAction = new QAction("&Enregistrer", this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip("Enregistrer le parachute");
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    fileMenu->addAction(saveAction);

    saveAsAction = new QAction("Enregistrer &sous...", this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip("Enregistrer sous un nouveau nom");
    connect(saveAsAction, &QAction::triggered, this, &MainWindow::saveFileAs);
    fileMenu->addAction(saveAsAction);

    fileMenu->addSeparator();

    exitAction = new QAction("&Quitter", this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip("Quitter l'application");
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
    fileMenu->addAction(exitAction);

    // Menu Edition
    editMenu = menuBar()->addMenu("&Edition");

    copyAction = new QAction("&Copier", this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip("Copier le texte");
    connect(copyAction, &QAction::triggered, this, &MainWindow::copyText);
    editMenu->addAction(copyAction);

    pasteAction = new QAction("&Coller", this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip("Coller le texte");
    connect(pasteAction, &QAction::triggered, this, &MainWindow::pasteText);
    editMenu->addAction(pasteAction);

    editMenu->addSeparator();

    clearAction = new QAction("&Effacer tout", this);
    clearAction->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Delete));
    clearAction->setStatusTip("Effacer tout le contenu");
    connect(clearAction, &QAction::triggered, this, &MainWindow::clearAll);
    editMenu->addAction(clearAction);

    // Menu Affichage
    viewMenu = menuBar()->addMenu("&Affichage");

    showHistoryAction = new QAction("Fenêtre d'&historique", this);
    showHistoryAction->setCheckable(true);
    showHistoryAction->setChecked(true);
    showHistoryAction->setStatusTip("Afficher/Masquer la fenêtre d'historique");
    connect(showHistoryAction, &QAction::toggled, this, &MainWindow::toggleHistoryWindow);
    viewMenu->addAction(showHistoryAction);

    showBinaryViewAction = new QAction("Vue &binaire", this);
    showBinaryViewAction->setCheckable(true);
    showBinaryViewAction->setChecked(true);
    showBinaryViewAction->setStatusTip("Afficher/Masquer la vue binaire");
    connect(showBinaryViewAction, &QAction::toggled, this, &MainWindow::toggleBinaryView);
    viewMenu->addAction(showBinaryViewAction);

    // Menu Aide
    helpMenu = menuBar()->addMenu("&Aide");

    helpAction = new QAction("&Aide", this);
    helpAction->setShortcut(QKeySequence::HelpContents);
    helpAction->setStatusTip("Afficher l'aide");
    connect(helpAction, &QAction::triggered, this, &MainWindow::showHelp);
    helpMenu->addAction(helpAction);

    aboutAction = new QAction("À &propos", this);
    aboutAction->setStatusTip("À propos de l'application");
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    helpMenu->addAction(aboutAction);
}

void MainWindow::newFile() {
    messageInput->clear();
    referenceCharInput->setText("@");
    sectorsInput->setValue(21);
    tracksInput->setValue(5);
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this,
        "Ouvrir un parachute", 
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "Fichiers parachute (*.para);;Tous les fichiers (*.*)");
        
    if (fileName.isEmpty())
        return;
        
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Erreur",
            QString("Impossible d'ouvrir le fichier %1:\n%2.")
            .arg(QDir::toNativeSeparators(fileName),
                 file.errorString()));
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject json = doc.object();
    
    // Charger les paramètres
    messageInput->setText(json["message"].toString());
    referenceCharInput->setText(json["referenceChar"].toString());
    sectorsInput->setValue(json["sectors"].toInt());
    tracksInput->setValue(json["tracks"].toInt());
    
    // Charger les couleurs
    QJsonObject color1Json = json["color1"].toObject();
    QJsonObject color2Json = json["color2"].toObject();
    
    ParachuteSettings settings = parachute->getSettings();
    settings.color1 = QColor(color1Json["r"].toInt(), 
                           color1Json["g"].toInt(), 
                           color1Json["b"].toInt());
    settings.color2 = QColor(color2Json["r"].toInt(), 
                           color2Json["g"].toInt(), 
                           color2Json["b"].toInt());
    parachute->setSettings(settings);
    
    updateViews();
    statusBar()->showMessage("Fichier chargé", 2000);
}

void MainWindow::saveFile() {
    if (currentFilePath.isEmpty()) {
        saveFileAs();
        return;
    }
    saveToFile(currentFilePath);
}

void MainWindow::saveFileAs() {
    QString fileName = QFileDialog::getSaveFileName(this,
        "Enregistrer le parachute",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "Fichiers parachute (*.para);;Tous les fichiers (*.*)");
        
    if (fileName.isEmpty())
        return;
    
    // Ajouter l'extension .para si non présente
    if (!fileName.endsWith(".para", Qt::CaseInsensitive))
        fileName += ".para";
        
    if (saveToFile(fileName)) {
        currentFilePath = fileName;
        statusBar()->showMessage("Fichier enregistré", 2000);
    }
}

bool MainWindow::saveToFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Erreur",
            QString("Impossible d'enregistrer le fichier %1:\n%2.")
            .arg(QDir::toNativeSeparators(fileName),
                 file.errorString()));
        return false;
    }
    
    QJsonObject json;
    json["message"] = messageInput->text();
    json["referenceChar"] = referenceCharInput->text();
    json["sectors"] = sectorsInput->value();
    json["tracks"] = tracksInput->value();
    
    // Sauvegarder les couleurs
    ParachuteSettings settings = parachute->getSettings();
    QJsonObject color1;
    color1["r"] = settings.color1.red();
    color1["g"] = settings.color1.green();
    color1["b"] = settings.color1.blue();
    json["color1"] = color1;
    
    QJsonObject color2;
    color2["r"] = settings.color2.red();
    color2["g"] = settings.color2.green();
    color2["b"] = settings.color2.blue();
    json["color2"] = color2;
    
    QJsonDocument doc(json);
    file.write(doc.toJson());
    return true;
}

void MainWindow::copyText() {
    messageInput->copy();
}

void MainWindow::pasteText() {
    messageInput->paste();
}

void MainWindow::clearAll() {
    messageInput->clear();
}

void MainWindow::toggleHistoryWindow(bool checked) {
    historyWindow->setVisible(checked);
}

void MainWindow::toggleBinaryView(bool checked) {
    binaryView->setVisible(checked);
}

void MainWindow::showAbout() {
    QMessageBox::about(this, "À propos",
        "Générateur de motifs de parachute\n\n"
        "Une application pour créer des motifs de parachute "
        "en encodant des messages en binaire.");
}

void MainWindow::showHelp() {
    QMessageBox::information(this, "Aide",
        "Pour utiliser cette application :\n\n"
        "1. Entrez votre message dans le champ texte\n"
        "2. Ajustez le nombre de secteurs et de pistes\n"
        "3. Choisissez vos couleurs\n"
        "4. Le motif se met à jour automatiquement");
}
