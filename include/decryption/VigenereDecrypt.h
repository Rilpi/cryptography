#ifndef VIGENEREDECRYPT_H
#define VIGENEREDECRYPT_H

#include <string>

class VigenereDecrypt
{
private:
    std::string key;

public:
    VigenereDecrypt(const std::string& k);

    std::string decrypt(const std::string& data);
};

#endif