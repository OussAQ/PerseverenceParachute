#include "parachute.h"

Parachute::Parachute() {}

void Parachute::setSettings(const ParachuteSettings& s) {
    settings = s;
}

const ParachuteSettings& Parachute::getSettings() const {
    return settings;
}

void Parachute::setMessage(const QString& msg) {
    message = msg;
    bits = convertToBits(msg);
}

QVector<bool> Parachute::getBits() const {
    return bits;
}

QVector<bool> Parachute::convertToBits(const QString& text) const {
    QVector<bool> result;
    for (QChar c : text) {
        int value = c.unicode() - settings.referenceChar.unicode();
        for (int i = 6; i >= 0; i--) {
            result.push_back((value >> i) & 1);
        }
    }
    return result;
}
