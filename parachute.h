#ifndef PARACHUTE_H
#define PARACHUTE_H

#include <QString>
#include <QVector>
#include <QColor>

class ParachuteSettings {
public:
    int sectors = 21;
    int tracks = 5;
    QChar referenceChar = '@';
    QColor color1 = Qt::white;
    QColor color2 = Qt::red;
    bool useRandomColors = false;
    bool use10BitBlocks = false;
    bool addMarkerPattern = false;
    bool emptyCenter = false;
    bool useSawTeeth = false;
};

class Parachute {
private:
    ParachuteSettings settings;
    QString message;
    QVector<bool> bits;

public:
    Parachute();
    void setSettings(const ParachuteSettings& s);
    const ParachuteSettings& getSettings() const;
    void setMessage(const QString& msg);
    QVector<bool> getBits() const;
    QVector<bool> convertToBits(const QString& text) const;
};
#endif
