#include "binaryview.h"
#include <QPainter>
#include <QDebug>

BinaryView::BinaryView(QWidget *parent) : QWidget(parent) {
    color0 = Qt::white;
    color1 = Qt::red;
    setMinimumSize(200, 100);
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
    return QSize(200, 50);
}

QSize BinaryView::minimumSizeHint() const {
    return QSize(50, 10);
}

void BinaryView::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    painter.fillRect(rect(), Qt::white);
    
    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(rect().adjusted(0, 0, -1, -1));
    
    if (!message.isEmpty()) {
        drawGrid(painter);
    }
}

void BinaryView::drawGrid(QPainter &painter) {
    int totalBits = message.length() * 7;
    if (totalBits == 0) return;
    
    int cols = (totalBits + DOTS_PER_COLUMN - 1) / DOTS_PER_COLUMN;
    if (cols <= 0) cols = 1;
    
    int dotSpacing = DOT_SPACING;
    
    int currentBit = 0;
    for (int i = 0; i < message.length() && currentBit < totalBits; ++i) {
        Message msg(QString(message[i]).toStdString().c_str());
        msg.setReferenceChar(referenceChar);
        std::vector<bool> bits = msg.getBitsForChar(0);
        
        for (size_t j = 0; j < bits.size() && currentBit < totalBits; ++j) {
            int col = (currentBit / DOTS_PER_COLUMN) % DOTS_PER_ROW;
            int row = currentBit % DOTS_PER_COLUMN + 9*((int) currentBit/(7*DOTS_PER_ROW));
            
            if (col >= cols) break;
            
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
