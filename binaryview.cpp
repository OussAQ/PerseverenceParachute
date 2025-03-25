#include "binaryview.h"
#include <QPainter>
#include <QDebug>

BinaryView::BinaryView(QWidget *parent) : QWidget(parent) {
    // Couleurs par défaut
    color0 = Qt::white;
    color1 = Qt::red;
    setMinimumSize(400, 100);  // Hauteur réduite pour un aspect plus horizontal
}

void BinaryView::setMessage(const QString &text, char refChar) {
    message = text;
    referenceChar = refChar;
    update();
}

void BinaryView::setColors(const QColor &c0, const QColor &c1) {
    color0 = c0;
    color1 = c1;
    update();
}

QSize BinaryView::sizeHint() const {
    return QSize(600, 100);  // Taille préférée plus horizontale
}

QSize BinaryView::minimumSizeHint() const {
    return QSize(400, 80);  // Taille minimum pour assurer la lisibilité
}

void BinaryView::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Fond blanc
    painter.fillRect(rect(), Qt::white);
    
    // Dessiner le cadre
    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
    
    if (!message.isEmpty()) {
        drawGrid(painter);
    }
}

void BinaryView::drawGrid(QPainter &painter) {
    int totalBits = message.length() * 7;
    if (totalBits == 0) return;
    
    // Calculer le nombre de lignes nécessaires
    int rows = (totalBits + DOTS_PER_ROW - 1) / DOTS_PER_ROW;
    if (rows <= 0) rows = 1;
    
    // Espacement fixe entre les points
    int dotSpacing = DOT_SPACING;
    
    // Dessiner les points
    int currentBit = 0;
    for (int i = 0; i < message.length() && currentBit < totalBits; ++i) {
        Message msg(QString(message[i]).toStdString().c_str());
        msg.setReferenceChar(referenceChar);
        std::vector<bool> bits = msg.getBitsForChar(0);
        
        for (size_t j = 0; j < bits.size() && currentBit < totalBits; ++j) {
            int row = currentBit / DOTS_PER_ROW;
            int col = currentBit % DOTS_PER_ROW;
            
            if (row >= rows) break;
            
            int x = MARGIN + col * (DOT_SIZE + dotSpacing);
            int y = MARGIN + row * (DOT_SIZE + dotSpacing);
            
            if (x + DOT_SIZE <= width() - MARGIN && y + DOT_SIZE <= height() - MARGIN) {
                painter.setBrush(bits[j] ? color1 : color0);
                painter.setPen(Qt::black);
                painter.drawEllipse(x, y, DOT_SIZE, DOT_SIZE);
            }
            
            currentBit++;
        }
    }
} 
