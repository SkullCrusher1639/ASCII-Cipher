/*
    Text File Cipher and Decipher Program
    Author: Hammad Bin Sajjad
    Program Idea/Challenge: A CodeBeauty Tutorial
    
    Functionality: Encrypts and decrypts a text file using ASCII Cipher

*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


char menu();
bool open_input_file(ifstream &file);
bool open_output_file(ofstream &file);
void cipher();
void decipher();

int main()
{
    // Menu
    while (true)
    {
        // Switch case based on what operation the user selects
        switch (menu())
        {
            case '1':
                {
                    system("cls");
                    cipher();
                    break;
                }
            
            case '2':
                {
                    system("cls");
                    decipher();
                    break;
                }

            case '3':
                {
                    system("cls");
                    exit(0);
                }

            default:
                {
                    cout << "Invalid Option" << endl << "Try Again" << endl;
                }
        }
    }
    
}

char menu()
{
    system("cls");
    // Variables
    char choice;

    // Menu
    cout << "Select Operation" << endl;
    cout << "1: Cipher" << endl;
    cout << "2: Decipher" << endl;
    cout << "3: Exit" << endl;

    // Operation selection
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    return choice;
}

bool open_input_file(ifstream &file)
{
    string file_name;
    cout << "Enter name of input file: ";
    getline(cin, file_name);
    file.open(file_name);
    if (file.fail())
    {
        cout << "Error Occured, Try Again" << endl;
        file.close();
        return false;
    }
	return true;
}

bool open_output_file(ofstream &file)
{
    string file_name;
    cout << "Enter name of output file: ";
    getline(cin, file_name);
    file.open(file_name);
    if (file.fail())
    {
        cout << "Error Occured, Try Again" << endl;
        file.close();
        return false;
    }
    return true;
}

void cipher()
{
    ifstream input_file;
    if (!open_input_file(input_file))
    {
        return;
    }

    ofstream output_file;
    if (!open_output_file(output_file))
    {
        return;
    }

    string data;
    int len;

    while (getline(input_file, data))
    {
        len = static_cast <int> (data.length());
        for (int i = 0; i < len; i++)
        {
            output_file << static_cast <int> (data[i]) << '\0';
        }
        output_file << endl;
    }

    output_file.close();
    input_file.close();

    cout << "Your ciphered file is ready" << endl;
}

void decipher()
{
    ifstream input_file;
    if (!open_input_file(input_file))
    {
        return;
    }

    ofstream output_file;
    if (!open_output_file(output_file))
    {
        return;
    }

    string data;
	char ASCII = '\0';
    int len;
    while (getline(input_file, data))
    {
        len = data.length();
        for (int i = 0; i < len; i++)
        {
            if (data[i] != '\0')
            {
                if (ASCII != 0) {
                    int temp = ASCII;
                    temp *= 10;
                    ASCII = (char)temp;
                }
                ASCII += data[i] - 48;
                continue;
            }
            else if (data[i] == '\0')
            {
                output_file << ASCII;
                ASCII = '\0';
            }
        }
        output_file << endl;
    }

    input_file.close();
    output_file.close();

    cout << "Your Deciphered file is ready" << endl;
}
