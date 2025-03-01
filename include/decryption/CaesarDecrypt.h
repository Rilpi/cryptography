#ifndef CAESARDECRYPT_H
#define CAESARDECRYPT_H

#include <string>

class CaesarDecrypt
{
private:
    int shift;

public:
    CaesarDecrypt(int s) : shift(s) {};
    
    std::string decrypt(const std::string& data);
};

#endif