#include <iostream>
#include <fstream>
#include "../../include/cryptography.h"

enum modes {encrypt, decrypt, invalid};

// Function prototypes
modes get_mode(const std::string& s);
int get_key(const std::string& s);
bool validate_filename(const std::string& file);
std::string get_data(const std::string& file);
void replace_data(const std::string& data);

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./caesar <Mode> <Key> <DataFile>" << std::endl;
    }

    // Validate args
    modes mode = get_mode(argv[1]);

    int key = get_key(argv[2]);
    if (key == 0)
        mode = invalid;

    std::string data_file = argv[3];
    validate_filename(data_file);
    
    // Get data from file
    std::string data = get_data(data_file);

    if (mode == encrypt)
    {
        CaesarEncrypt encryptor(key);
        data = encryptor.encrypt(data);
    }
    else if (mode == decrypt)
    {
        CaesarDecrypt decryptor(key);
        data = decryptor.decrypt(data);
    }
    else
    {
        std::cout << "Invalid arguments" << std::endl;
        return 0;
    }

    replace_data(data);
}

modes get_mode(const std::string& s)
{
    if (s == "encrypt")
        return encrypt;
    else if (s == "decrypt")
        return decrypt;
    else 
        return invalid;
}

int get_key(const std::string& s)
{
    for (auto i : s)
    {
        if (!isdigit(i))
            return 0;
    }

    return std::stoi(s);
}

bool validate_filename(const std::string& file)
{
    // TODO
}

std::string get_data(const std::string& file)
{
    // TODO
}

void replace_data(const std::string& data)
{
    // TODO
}