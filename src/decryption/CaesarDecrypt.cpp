#include "../../include/decryption/CaesarDecrypt.h"

std::string CaesarDecrypt::decrypt(const std::string& data)
{
    std::string cipher;
    for (auto i : data)
    {
        if (isalpha(i))
        {
            cipher += ((tolower(i) - 'a' - shift) % 26 + 'a'); 
        }
        else
        {
            cipher += i;
        }
    }
    return cipher;
}