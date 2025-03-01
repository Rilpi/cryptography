#include "../../include/decryption/CaesarDecrypt.h"

std::string decrypt(const std::string& data)
{
    std::string cipher;
    for (auto i : data)
    {
        cipher += (tolower(i) - 'a' + shift) % 26 + 'a'; 
    }
    return cipher;
}