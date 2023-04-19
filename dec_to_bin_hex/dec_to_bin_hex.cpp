#include <iostream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <cmath>
#include <cstring>
#include <string>

std::string dec_to_binary(int dec) {
    std::string bin{};
    std::cout << "================= Calculation... =================" << std::endl;
    for (size_t i{ 0 }; dec > 0; i++) {
        bin += std::to_string(dec % 2);
        std::cout << std::setw(8) << std::right << dec << " / " << 2 << std::setw(8) << std::right << "r. " << dec%2 << std::endl;
        dec = dec / 2;
    }
    //reverse string
    std::reverse(bin.begin(), bin.end());
    std::cout << "==================================================" << std::endl;
    return bin;
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
    default:
        std::cerr << "Error in calculation..." << std::endl;
    }
    return temp;
}

std::string dec_to_hex(int dec) {
    std::string bin{ dec_to_binary(dec)};
    std::reverse(bin.begin(), bin.end());
    std::string hex{};
    uint8_t hex_val{ 0 };
    int j{ 0 };
    for (size_t i{ 1 }; i <= bin.size(); ++i) { 
        hex_val += int((bin.at(i - 1)) - '0') * int(pow(2, j));
        j++;
        if (!(i % 4) && i != 0) {
            hex += value_to_char(hex_val);
            hex_val = 0;
            j = 0;
        }
        else if (i >= bin.size()) {
            hex += value_to_char(hex_val);
            std::reverse(hex.begin(), hex.end());
            return hex;
        }
    }
    std::reverse(hex.begin(), hex.end());
    return hex;
}

int main()
{
    int num{};
    std::cout << "Enter value: ";
    std::cin >> num;
    //entering a num
    while (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Wrong value..." << std::endl;
        std::cout << "Enter correct value: ";
        std::cin >> num;
    }
    //dec to bin
    std::string bin_str{};
    bin_str = dec_to_binary(abs(num));
    std::cout << num << " decimal to binary: 0b" << ((num >= 0) ? "" : "-") << bin_str << std::endl;
    //dec to hex
    std::string hex_str;
    hex_str = dec_to_hex(abs(num));
    std::cout << num << " decimal to hex: 0x" << ((num >= 0) ? "" : "-") << hex_str << std::endl;
    /*
    display_bin(bin);
    hex = dec_to_hex(num);
    display_hex(hex);
    */
    return 0;
}