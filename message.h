#ifndef MESSAGE_H
#define MESSAGE_H


class Message
{
public:
    Message();
    Message(char *);
    char getK(int index);
    int * getKBin(int index);
    void showBinary();
    void setNewZero(char);
private:
    char * _message;
    int _size;
    int ** _binary;
    char _zero;
    void toBinary();
};

#endif // MESSAGE_H
