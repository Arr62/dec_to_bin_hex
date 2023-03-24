/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <cmath>
#include <cstring>

std::vector<bool> dec_to_binary(int dec) {
    int dec_o{ dec };
    std::vector<bool> bin;
    for (int i{ 0 }; dec > 0; i++) {
        bin.push_back(dec % 2);
        //std::cout << std::setw(4) << dec << " / " << 2 << "\tr. " << dec%2 << std::endl;
        dec = dec / 2;
    }
    return bin;
}
void display_bin(std::vector<bool> bin) {
    std::cout << std::endl;
    std::cout << "binary : 0b";
    for (size_t i{ (bin.size()) - 1 }; i >= 0 && i < ULONG_MAX; i--) {
        std::cout << bin.at(i);
    }
    std::cout << std::endl;
}

char* dec_to_hex(int dec) {
    std::vector<bool> bin{ dec_to_binary(dec) };
    char* hex;
    size_t size{ 0 };

    if (bin.size() % 4 != 0) {
        hex = new char[(bin.size() / 4) + 2];
        hex[(bin.size() / 4) + 1] = '\0';
        size = ((bin.size() / 4) + 1) * 4;
    }
    else {
        hex = new char[(bin.size() / 4) + 1];
        hex[(bin.size() / 4)] = '\0';
        size = (bin.size() / 4) * 4;
    }

    int temp{ 0 };
    int counter{ 0 };
    int k{ 0 };
    for (long unsigned int i{ 0 }; i < size; i++) {
        if (i > bin.size() - 1) {
            bin.push_back(0);
        }
    }

    for (long unsigned int i{ 0 }; i <= size; ++i) {
        if (i % 4 == 0 && i != 0) {
            switch (temp) {
            case 0:
                hex[counter] = '0';
                break;
            case 1:
                hex[counter] = '1';
                break;
            case 2:
                hex[counter] = '2';
                break;
            case 3:
                hex[counter] = '3';
                break;
            case 4:
                hex[counter] = '4';
                break;
            case 5:
                hex[counter] = '5';
                break;
            case 6:
                hex[counter] = '6';
                break;
            case 7:
                hex[counter] = '7';
                break;
            case 8:
                hex[counter] = '8';
                break;
            case 9:
                hex[counter] = '9';
                break;
            case 10:
                hex[counter] = 'A';
                break;
            case 11:
                hex[counter] = 'B';
                break;
            case 12:
                hex[counter] = 'C';
                break;
            case 13:
                hex[counter] = 'D';
                break;
            case 14:
                hex[counter] = 'E';
                break;
            case 15:
                hex[counter] = 'F';
                break;
            default:
                break;
            }
            counter++;
            temp = 0;
            k = 0;
        }
        if (i < bin.size()) {
            temp = temp + (int)(bin.at(i) * pow(2.0, k));
            k++;
        }
    }
    return hex;
}

void display_hex(char* hex) {
    std::cout << "hex : 0x";
    for (size_t i{ strlen(hex) - 1 }; i >= 0 && i < ULONG_MAX; i--) {
        std::cout << hex[i];
    }
    std::cout << std::endl;
}

int main()
{
    int num{ 0 };
    std::cout << "Enter value: ";
    std::cin >> num;
    char* hex;
    std::vector<bool> bin;
    bin = dec_to_binary(num);
    display_bin(bin);
    hex = dec_to_hex(num);
    display_hex(hex);

    return 0;
}

