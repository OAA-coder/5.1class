#include "FixedLengthStringArray.h"
#include "helpers.h"
#include <iostream>
#include <stdexcept>

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Демонстрационная программа: Массив строк фиксированной длины\n";

    try {
        // Создаем два массива для демонстрации
        int size = inputNumber("Введите размер массивов: ");
        int str_len = inputNumber("Введите максимальную длину строк: ");

        // Инициализация массивов
        FixedLengthStringArray array1(size, str_len);
        FixedLengthStringArray array2(size, str_len);

        // Заполнение первого массива
        std::cout << "\nЗаполнение первого массива:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "Введите строку " + std::to_string(i + 1) +
                " (макс. " + std::to_string(str_len) + " символов): ";
            array1[i] = inputString(prompt, str_len);
        }

        // Заполнение второго массива
        std::cout << "\nЗаполнение второго массива:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "Введите строку " + std::to_string(i + 1) +
                " (макс. " + std::to_string(str_len) + " символов): ";
            array2[i] = inputString(prompt, str_len);
        }

        // Основное меню программы
        while (true) {
            std::cout << "\nМеню:\n";
            std::cout << "1. Вывести элемент первого массива по индексу\n";
            std::cout << "2. Вывести все элементы первого массива\n";
            std::cout << "3. Вывести элемент второго массива по индексу\n";
            std::cout << "4. Вывести все элементы второго массива\n";
            std::cout << "5. Объединить массивы поэлементно\n";
            std::cout << "6. Объединить массивы с удалением дубликатов\n";
            std::cout << "7. Выход\n";

            int choice = inputNumber("Выберите пункт меню: ", 1);

            try {
                switch (choice) {
                case 1: {
                    // Вывод элемента первого массива по индексу
                    int index = inputNumber("Введите индекс: ", 0);
                    array1.printElement(index);
                    break;
                }
                case 2:
                    // Вывод всех элементов первого массива
                    array1.printAll();
                    break;
                case 3: {
                    // Вывод элемента второго массива по индексу
                    int index = inputNumber("Введите индекс: ", 0);
                    array2.printElement(index);
                    break;
                }
                case 4:
                    // Вывод всех элементов второго массива
                    array2.printAll();
                    break;
                case 5: {
                    // Конкатенация массивов
                    FixedLengthStringArray result = array1.concatenate(array2);
                    std::cout << "Результат объединения:\n";
                    result.printAll();
                    break;
                }
                case 6: {
                    // Слияние массивов с удалением дубликатов
                    FixedLengthStringArray result = array1.mergeUnique(array2);
                    std::cout << "Результат слияния с удалением дубликатов:\n";
                    result.printAll();
                    break;
                }
                case 7:
                    // Выход из программы
                    std::cout << "Завершение программы.\n";
                    return 0;
                default:
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
                }
            }
            catch (const std::exception& e) {
                // Обработка ошибок в операциях меню
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        // Обработка критических ошибок инициализации
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}