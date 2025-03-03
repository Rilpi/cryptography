#ifndef VIGENEREENCRYPT_H
#define VIGENEREENCRYPT_H

#include <string>

class VigenereEncrypt
{
private:
    std::string key;

public:
    VigenereEncrypt(const std::string& k);

    std::string encrypt(const std::string& data);
};

#endif