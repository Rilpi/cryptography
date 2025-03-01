#ifndef CAESARENCRYPT_H
#define CAESARENCRYPT_H

#include <string>

class CaesarEncrypt 
{
private:
    int shift;

public:
    CaesarEncrypt(int s) : shift(s) {};

    std::string encrypt(const std::string& data);
};

#endif