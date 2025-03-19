#ifndef PARACHUTE_H
#define PARACHUTE_H

#include "message.h"

class parachute
{
public:
    parachute();
    parachute(char *,int,int);
    void setSectors(int);
    void setPistes(int);
    int getSectors();
private:
    int _nbPistes;
    int _nbSectors;
    Message * _message;
};

#endif // PARACHUTE_H
