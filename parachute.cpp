#include "parachute.h"

parachute::parachute()
{
    _message=new Message();
    _nbPistes=0;
    _nbSectors=0;
}

parachute::parachute(char * message,int nbPistes,int nbSectors){
    _message =  new Message(message);
    _nbPistes = nbPistes;
    _nbSectors = nbSectors;
}

void parachute::setSectors(int nbSectors){
    _nbSectors=nbSectors;
}

void parachute::setPistes(int nbPistes){
    _nbPistes=nbPistes;
}

int parachute::getSectors(){
    return _nbSectors;
}
