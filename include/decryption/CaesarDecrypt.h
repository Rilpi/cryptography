#ifndef CAESARDECRYPT_H
#define CAESARDECRYPT_H

#include <string>

class CaesarDecrypt
{
private:
    int key;

public:
    CaesarDecrypt(int k) : key(k) {};
    
    std::string decrypt(const std::string& data);
};

#endif