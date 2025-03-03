#include "../../include/encryption/VigenereEncrypt.h"

VigenereEncrypt::VigenereEncrypt(const std::string& k)
{
    // Set key to lowercase of given string
    for (auto i : k)
    {
        key += tolower(i);
    }
}

std::string VigenereEncrypt::encrypt(const std::string& data)
{
    std::string cipher;

    // Iterate over each plain text and key character
    int kpos = 0;
    for (auto i : data)
    {
        if (isalpha(i))
        {
            // Reset key after end to repeat
            if (kpos >= key.length())
                kpos = 0;

            // Add converted character
            cipher += ((tolower(i) - 'a') + (key[kpos] - 'a')) % 26 + 'a';

            kpos++;
        }
        else
        {
            // Non-alphabetic character
            cipher += i;
        }
    }

    return cipher;
}
