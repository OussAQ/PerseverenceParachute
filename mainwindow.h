#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "parachute.h"
#include "parachutewidget.h"
#include "message.h"
#include "binaryview.h"

// Classe pour la fenêtre d'historique
class HistoryWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = nullptr);
    void updateHistory(const QString &text);

private:
    QTextEdit* historyText;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QString currentFilePath;
    Parachute* parachute;
    ParachuteWidget* parachuteWidget;
    HistoryWindow* historyWindow;
    BinaryView* binaryView;
    QLineEdit* messageInput;
    QLineEdit* referenceCharInput;
    QSpinBox* sectorsInput;
    QSlider* sectorsSlider;
    QSpinBox* tracksInput;
    QSlider* tracksSlider;

    // Menus
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *clearAction;
    QAction *showHistoryAction;
    QAction *showBinaryViewAction;
    QAction *aboutAction;
    QAction *helpAction;

    void setupUI();
    void setupMenus();
    void updateParachute();
    void updateBitsDisplay(const QString &text);
    void updateViews();
    bool saveToFile(const QString &fileName);

private slots:
    void onMessageChanged(const QString &text);
    void onReferenceCharChanged();
    void onSectorsSpinBoxChanged(int value);
    void onSectorsSliderChanged(int value);
    void onTracksSpinBoxChanged(int value);
    void onTracksSliderChanged(int value);
    void generateRandomColors();
    void resetColors();
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void copyText();
    void pasteText();
    void clearAll();
    void toggleHistoryWindow(bool checked);
    void toggleBinaryView(bool checked);
    void showAbout();
    void showHelp();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif
