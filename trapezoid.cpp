#include "trapezoid.h"

Trapezoid::Trapezoid(double radius, int tracks, int sectors, int index)
    : R(radius), T(tracks), S(sectors), k(index) {
    angleElement = 2 * M_PI / S;
    trackWidth = R / T;
    sectorNumber = k % S;
    trackNumber = k / S;
}

QPointF Trapezoid::getP1() const {
    double alpha1 = sectorNumber * angleElement;
    double rp = trackNumber * trackWidth;
    return QPointF(rp * cos(alpha1), rp * sin(alpha1));
}

QPointF Trapezoid::getP2() const {
    double alpha2 = (sectorNumber + 1) * angleElement;
    double rp = trackNumber * trackWidth;
    return QPointF(rp * cos(alpha2), rp * sin(alpha2));
}

QPointF Trapezoid::getQ1() const {
    double alpha1 = sectorNumber * angleElement;
    double rq = (trackNumber + 1) * trackWidth;
    return QPointF(rq * cos(alpha1), rq * sin(alpha1));
}

QPointF Trapezoid::getQ2() const {
    double alpha2 = (sectorNumber + 1) * angleElement;
    double rq = (trackNumber + 1) * trackWidth;
    return QPointF(rq * cos(alpha2), rq * sin(alpha2));
}
