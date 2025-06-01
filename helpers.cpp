#include "helpers.h"
#include <iostream>

// Функция для ввода целого числа с валидацией
// prompt - приглашение для ввода
// minValue - минимальное допустимое значение
int inputNumber(const std::string& prompt, int minValue) {
    int value;
    while (true) {
        std::cout << prompt;  // Выводим приглашение для ввода
        std::cin >> value;     // Считываем введённое значение

        // Проверяем корректность ввода
        if (std::cin.fail() || value < minValue) {
            std::cin.clear();  // Сбрасываем флаги ошибок
            // Очищаем буфер ввода до конца строки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Выводим сообщение об ошибке
            std::cout << "Некорректный ввод. Пожалуйста, введите число >= " << minValue << std::endl;
        }
        else {
            // Очищаем буфер от возможных остаточных символов
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;  // Возвращаем корректное значение
        }
    }
}

// Функция для ввода строки с проверкой максимальной длины
// prompt - приглашение для ввода
// maxLength - максимально допустимая длина строки
std::string inputString(const std::string& prompt, size_t maxLength) {
    std::string str;
    while (true) {
        std::cout << prompt;        // Выводим приглашение для ввода
        std::getline(std::cin, str); // Считываем всю строку

        // Проверяем длину введённой строки
        if (str.length() > maxLength) {
            std::cout << "Слишком длинная строка. Максимальная длина: "
                << maxLength << ". Пожалуйста, попробуйте снова." << std::endl;
        }
        else {
            return str;  // Возвращаем корректную строку
        }
    }
}