#ifndef VIGENEREENCRYPT_H
#define VIGENEREENCRYPT_H

#include <string>

class VigenereEncrypt
{
private:
    std::string key;

public:
    VigenereEncrypt(std::string k) : key(k) {};

    std::string encrypt(const std::string& data);
};

#endif