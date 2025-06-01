#ifndef HELPERS_H       // Проверка, не был ли этот заголовочный файл уже подключен
#define HELPERS_H       // Определение макроса, чтобы предотвратить повторное включение

#include <iostream>     // Для работы с вводом/выводом (std::cin, std::cout)
#include <limits>      // Для работы с пределами числовых типов (std::numeric_limits)
#include <string>      // Для работы со строками (std::string)

// Функция для ввода целого числа с проверкой диапазона
int inputNumber(const std::string& prompt, int minValue = 1);

// Функция для ввода строки с проверкой максимальной длины
std::string inputString(const std::string& prompt, size_t maxLength);

#endif     // Конец условия препроцессора