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
        std::cout << std::setw(8) << std::right << dec << " / " << 2 << std::setw(8) << std::right << "r. " << dec%2 << std::endl;
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
    case 6:
        temp = '6';
        break;
    case 7:
        temp = '7';
        break;
    case 8:
        temp = '8';
        break;
    case 9:
        temp = '9';
        break;
    case 10:
        temp = 'a';
        break;
    case 11:
        temp = 'b';
        break;
    case 12:
        temp = 'c';
        break;
    case 13:
        temp = 'd';
        break;
    case 14:
        temp = 'e';
        break;
    case 15:
        temp = 'f';
        break;
    }
    return temp;
}
std::vector<char> dec_to_hex(int dec) {
    std::vector<bool> bin{ dec_to_binary(dec) };
    std::vector<char> hex;
    int hex_val{ 0 };
    int j{ 0 };
    for (size_t i{ 1 }; i <= bin.size(); ++i) { 
        hex_val += (int)(bin.at(i - 1) * pow(2, j));
        j++;
        if (!(i % 4) && i != 0) {
            hex.push_back(value_to_char(hex_val));
            hex_val = 0;
            j = 0;
        }
        else if (i == bin.size()) {
            hex.push_back(value_to_char(hex_val));
            return hex;
        }
    }
    return hex;
}

std::string display_hex(std::vector<char> bin) {
    std::string bin_str;
    for (size_t i{ 1 }; i < bin.size() + 1; i++) {
        bin_str += bin.at(bin.size() - i);
    }
    return bin_str;
}

int main()
{
    int num{ };
    std::cout << "Enter value: ";
    std::cin >> num;
    //dec to bin
    std::string bin_str;
    bin_str = display_bin(dec_to_binary(num));
    std::cout << num << " decimal to binary: 0b" << bin_str << std::endl;
    //dec to hex
    std::string hex_str;
    std::vector <char> hex;
    hex_str = display_hex(dec_to_hex(num));
    std::cout << num << " decimal to hex: 0x" << hex_str << std::endl;
    /*
    display_bin(bin);
    hex = dec_to_hex(num);
    display_hex(hex);
    */
    return 0;
}