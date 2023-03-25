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
#include <string>

std::vector<bool> dec_to_binary(int dec) {
    int dec_o{ dec };
    std::vector<bool> bin;
    std::cout << "================= Calculation... =================" << std::endl;
    for (size_t i{ 0 }; dec > 0; i++) {
        bin.push_back(dec % 2);
        std::cout << std::setw(6) << dec << " / " << 2 << "\tr. " << dec%2 << std::endl;
        dec = dec / 2;
    }
    std::cout << "==================================================" << std::endl;
    return bin;
}
std::string display_bin(std::vector<bool> bin) {
    std::string bin_str;
    for (size_t i{ 1 }; i < bin.size() + 1; i++) {
        bin_str += std::to_string(bin.at(bin.size() - i));
    }
    return bin_str;
}

char value_to_char(int dec) {
    char temp{};
    switch (dec) {
    case 0:
        temp = '0';
        break;
    case 1:
        temp = '1';
        break;
    case 2:
        temp = '2';
        break;
    case 3:
        temp = '3';
        break;
    case 4:
        temp = '4';
        break;
    case 5:
        temp = '5';
        break;
    }
}
std::vector<char> dec_to_hex(int dec) {
    std::vector<bool> bin{ dec_to_binary(dec) };
    std::vector<char> hex;
    int i{ 0 };
    int hex_val{ 0 };
    for (const auto& b : bin) {
        hex_val += pow(2, i);
        i++;
        if (!(i % 4)) {
            hex.push_back(char(hex_val));
            i = 0;
        }
        else if (b == bin.at(bin.size() - 1)) {
            hex.push_back(char(hex_val));
            return hex;
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
    //dec to bin
    //std::string bin_str;
    //bin_str = display_bin(dec_to_binary(num));
    //std::cout << num << " decimal to binary : 0b" << bin_str << std::endl;
    //dec to hex
    std::string hex_str;
    std::vector <char> hex;
    hex = dec_to_hex(num);
    std::cout << hex.size() << std::endl;
    for (const auto& h : hex) {
        std::cout << h;
    }
    //hex_str = display_hex(dec_to_hex(num));
    /*
    display_bin(bin);
    hex = dec_to_hex(num);
    display_hex(hex);
    */
    return 0;
}

