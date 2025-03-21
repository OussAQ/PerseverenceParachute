#include "parachutewidget.h"

ParachuteWidget::ParachuteWidget(QWidget* parent)
    : QWidget(parent), parachute(nullptr) {
    setMinimumSize(400, 400);
}

void ParachuteWidget::setParachute(Parachute* p) {
    parachute = p;
    update();
}

void ParachuteWidget::paintEvent(QPaintEvent*) {
    if (!parachute) return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);

    double radius = qMin(width(), height()) * 0.45;

    for (int k = 0; k < parachute->getSettings().sectors * parachute->getSettings().tracks; k++) {
        Trapezoid trapezoid(radius,
                          parachute->getSettings().tracks,
                          parachute->getSettings().sectors,
                          k);

        QPainterPath path;
        path.moveTo(trapezoid.getP1());
        path.lineTo(trapezoid.getP2());
        path.lineTo(trapezoid.getQ2());
        path.lineTo(trapezoid.getQ1());
        path.closeSubpath();

        if (k < parachute->getBits().size()) {
            painter.setBrush(parachute->getBits()[k] ?
                           parachute->getSettings().color2 :
                           parachute->getSettings().color1);
        } else {
            painter.setBrush(parachute->getSettings().color1);
        }

        painter.setPen(Qt::black);
        painter.drawPath(path);
    }
}
