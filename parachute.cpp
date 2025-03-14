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
