#include <iostream>
#include <cstring>
#include <bitset>
#include <sstream>
#include "message.h"

Message::Message() : _message(nullptr), _size(0), _zero('@') {
    _message = new char[1];
    _message[0] = '\0';
}

Message::Message(const char* message) : _zero('@') {
    _size = strlen(message);
    _message = new char[_size + 1];
    strcpy(_message, message);
    toBinary();
}

Message::~Message() {
    delete[] _message;
}

void Message::cleanup() {
    _binary.clear();
}

void Message::toBinary() {
    cleanup();
    _binary.resize(_size);
    
    for (int i = 0; i < _size; i++) {
        _binary[i].resize(7);  // 7 bits par caractère
        char cur = (_message[i] - _zero) % 128;  // Limite à 7 bits ASCII
        
        // Conversion en binaire 7 bits
        for (int j = 0; j < 7; j++) {
            _binary[i][6-j] = (cur % 2) == 1;
            cur /= 2;
        }
    }
}

bool Message::getBit(int bitIndex) const {
    if (bitIndex < 0 || bitIndex >= getTotalBits()) {
        std::cerr << "Index de bit hors limites" << std::endl;
        return false;
    }
    
    int charIndex = bitIndex / 7;  // 7 bits par caractère
    int bitPosition = bitIndex % 7;
    return _binary[charIndex][bitPosition];
}

int Message::getTotalBits() const {
    return _size * 7;  // 7 bits par caractère
}

char Message::getChar(int index) const {
    if (index >= 0 && index < _size) {
        return _message[index];
    }
    std::cerr << "Index de caractère hors limites" << std::endl;
    return '\0';
}

std::vector<bool> Message::getBitsForChar(int charIndex) const {
    if (charIndex >= 0 && charIndex < _size) {
        return _binary[charIndex];
    }
    return std::vector<bool>();
}

void Message::showBinary() const {
    for (int i = 0; i < _size; i++) {
        std::cout << "Caractère '" << _message[i] << "' (ASCII-7: " << (int)(_message[i] - _zero) 
                 << "): ";
        for (int j = 0; j < 7; j++) {
            std::cout << (_binary[i][j] ? '1' : '0');
        }
        std::cout << std::endl;
    }
}

std::string Message::getBinaryString() const {
    std::stringstream ss;
    for (int i = 0; i < _size; i++) {
        for (int j = 0; j < 7; j++) {
            ss << (_binary[i][j] ? '1' : '0');
        }
    }
    return ss.str();
}

void Message::setReferenceChar(char zero) {
    _zero = zero;
    toBinary();
}
