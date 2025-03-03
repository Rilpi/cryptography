#include <iostream>
#include <fstream>
#include "../../include/cryptography.h"

enum modes {encrypt, decrypt, invalid};

// Function prototypes
modes get_mode(const std::string& s);
int get_key(const std::string& s);
void get_data(std::ifstream& ifile, std::string& data);
void replace_data(const std::string& file, const std::string& data);

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./caesar <Mode> <Key> <DataFile>" << std::endl;
    }
    else
    {

        // Validate mode
        modes mode = get_mode(argv[1]);

        // Validate key
        int key = get_key(argv[2]);
        if (key == 0)
            mode = invalid;

        // Get data from file
        std::string data;
        std::string file_name = argv[3];
        std::ifstream ifile(file_name, std::ios::in);

        if (!ifile.is_open()) // Invalid file
        {
            mode = invalid;
        }
        else // Valid file
        {
            get_data(ifile, data);
        }

        ifile.close();

        // Execute selected mode
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

        // Replace initial data with transformed data
        replace_data(file_name, data);
    }
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

void get_data(std::ifstream& ifile, std::string& data)
{
    while (!ifile.eof())
    {
        std::string s;
        ifile >> s;
        data += s + " ";
    }
}

void replace_data(const std::string& file, const std::string& data)
{
    std::ofstream ofile(file, std::ios::out);
    ofile << data;
    ofile.close();
}