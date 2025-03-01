#include "../../include/encryption/CaesarEncrypt.h"

std::string CaesarEncrypt::encrypt(const std::string& data)
{
    std::string cipher;
    for (auto i : data)
    {
        cipher += (tolower(i) - 'a' + shift) % 26 + 'a'; 
    }
    return cipher;
}