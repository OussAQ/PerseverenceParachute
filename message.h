#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>
#include <string>

class Message
{
public:
    Message();
    Message(const char* message);
    ~Message();
    
    // Accès aux bits et caractères
    bool getBit(int bitIndex) const;  // Accès au k-ième bit du message complet
    int getTotalBits() const;         // Nombre total de bits dans le message (N*7)
    char getChar(int index) const;    // Accès au k-ième caractère
    std::vector<bool> getBitsForChar(int charIndex) const; // Retourne les 7 bits du caractère
    
    // Utilitaires
    void showBinary() const;  // Affiche la représentation binaire
    void setReferenceChar(char zero);  // Définit le caractère de référence
    int getSize() const { return _size; }  // Nombre de caractères
    std::string getBinaryString() const;  // Retourne la séquence binaire complète
    
private:
    char* _message;
    int _size;
    std::vector<std::vector<bool>> _binary;  // Stockage des bits (7 bits par caractère)
    char _zero;  // Caractère de référence
    
    void toBinary();  // Conversion en binaire 7 bits
    void cleanup();
};

#endif // MESSAGE_H
