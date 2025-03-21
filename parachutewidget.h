#ifndef PARACHUTEWIDGET_H
#define PARACHUTEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include "parachute.h"
#include "trapezoid.h"

class ParachuteWidget : public QWidget {
    Q_OBJECT

private:
    Parachute* parachute;

protected:
    void paintEvent(QPaintEvent*) override;

public:
    ParachuteWidget(QWidget* parent = nullptr);
    void setParachute(Parachute* p);
};
#endif
