#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <QPointF>
#include <cmath>

class Trapezoid {
private:
    double R;
    int T;
    int S;
    int k;
    double angleElement;
    double trackWidth;
    int sectorNumber;
    int trackNumber;

public:
    Trapezoid(double radius, int tracks, int sectors, int index);
    QPointF getP1() const;
    QPointF getP2() const;
    QPointF getQ1() const;
    QPointF getQ2() const;
};
#endif
