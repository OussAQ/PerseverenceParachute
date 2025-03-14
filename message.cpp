#include <iostream>
#include "message.h"
#include <cstring>

Message::Message()
{
    _message=new char[1];
    _message[0]='\0';
    _size=0;

}

Message::Message(char * message){
    _message=message;
    _size=strlen(message);
    toBinary();
}

void Message::toBinary(){
    _binary = new int*[_size];
    char cur;
    for (int i=0;i<_size;i++){
        _binary[i]=new int[8];
        cur=(_message[i]-'@')%256;
        for(int j=0;j<8;j++){
            _binary[i][7-j] = cur%2;
            cur=cur/2;
        }
    }
}

char Message::getK(int index){
    if (index>0 && index<_size){
        return _message[index];
    }
}

int * Message::getKBin(int index){
    if (index>0 && index<_size){
        return _binary[index];
    }
}

void Message::showBinary(){
    for (int i=0;i<_size;i++){
        for(int j=0;j<8;j++){
            std::cout<<_binary[i][j];
        }
        std::cout<<std::endl;
    }
}
