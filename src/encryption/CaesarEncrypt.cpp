#include "../../include/encryption/CaesarEncrypt.h"
//test
#include <iostream>

std::string CaesarEncrypt::encrypt(const std::string& data)
{
    std::string cipher;
    for (auto i : data)
    {
        if (isalpha(i))
        {
            cipher += ((tolower(i) - 'a' + shift) % 26 + 'a');
        }
        else
        {
            cipher += i;
        } 
    }
    
    return cipher;
}