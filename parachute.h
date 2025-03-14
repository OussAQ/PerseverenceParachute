#ifndef PARACHUTE_H
#define PARACHUTE_H

#include "message.h"

class parachute
{
public:
    parachute();
    parachute(char *,int,int);
private:
    int _nbPistes;
    int _nbSectors;
    Message * _message;
};

#endif // PARACHUTE_H
