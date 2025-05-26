#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <limits>
#include <string>

int inputNumber(const std::string& prompt, int minValue = 1);
std::string inputString(const std::string& prompt, size_t maxLength);

#endif // HELPERS_H‘‘