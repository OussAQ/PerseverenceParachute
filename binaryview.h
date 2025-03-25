#ifndef BINARYVIEW_H
#define BINARYVIEW_H

#include <QWidget>
#include <QPainter>
#include "message.h"

class BinaryView : public QWidget {
    Q_OBJECT

public:
    explicit BinaryView(QWidget *parent = nullptr);
    void setMessage(const QString &text, char referenceChar = '@');
    void setColors(const QColor &color0, const QColor &color1);

protected:
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

private:
    QString message;
    char referenceChar;
    QColor color0;
    QColor color1;
    static const int DOT_SIZE = 8;       // Taille réduite des points
    static const int DOT_SPACING = 2;    // Espacement réduit entre les points
    static const int MARGIN = 10;        // Marge autour de la grille
    static const int DOTS_PER_ROW = 50;  // Nombre de points par ligne

    void drawGrid(QPainter &painter);
};

#endif // BINARYVIEW_H
