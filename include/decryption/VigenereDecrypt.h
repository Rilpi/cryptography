#ifndef VIGENEREDECRYPT_H
#define VIGENEREDECRYPT_H

#include <string>

class VigenereDecrypt
{
private:
    std::string key;

public:
    VigenereDecrypt(std::string k) : key(k) {};

    std::string decrypt(const std::string& data);
};

#endif