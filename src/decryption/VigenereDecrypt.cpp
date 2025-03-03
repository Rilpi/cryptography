#include "../../include/decryption/VigenereDecrypt.h"

VigenereDecrypt::VigenereDecrypt(const std::string& k)
{
    // Set key to lowercase of given string
    for (auto i : k)
    {
        key += tolower(i);
    }
}

std::string VigenereDecrypt::decrypt(const std::string& data)
{
    std::string plain;

    // Iterate over each cipher text and key character
    int kpos = 0;
    for (auto i : data)
    {
        if (isalpha(i))
        {
            // Reset key after end to repeat
            if (kpos >= key.length())
                kpos = 0;

            // Add converted character
            plain += ((tolower(i) - 'a' + 26) - key[kpos] - 'a') % 26 + 'a';
            
            kpos++;
        }
        else
        {
            // Non alphabetic character
            plain += i;
        }
        
    }

    return plain;
}