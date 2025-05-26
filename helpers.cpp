#include "helpers.h"
#include <iostream>

int inputNumber(const std::string& prompt, int minValue) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < minValue) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number >= " << minValue << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::string inputString(const std::string& prompt, size_t maxLength) {
    std::string str;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, str);
        if (str.length() > maxLength) {
            std::cout << "String too long. Maximum length is " << maxLength << ". Try again." << std::endl;
        }
        else {
            return str;
        }
    }
}