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
        cur=_message[i];
        for(int j=0;j<8;j++){
            _binary[i][7-j] = cur%2;
            cur=cur/2;
        }
    }
}
