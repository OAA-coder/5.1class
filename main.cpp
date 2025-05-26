#include "FixedLengthStringArray.h"
#include "helpers.h"
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "Fixed Length String Array Demo Program\n";

    try {
        // Создаем два массива для демонстрации
        int size = inputNumber("Enter array size: ");
        int str_len = inputNumber("Enter maximum string length: ");

        FixedLengthStringArray array1(size, str_len);
        FixedLengthStringArray array2(size, str_len);

        // Заполнение первого массива
        std::cout << "\nFilling first array:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "Enter string " + std::to_string(i + 1) + " (max " + std::to_string(str_len) + " chars): ";
            array1[i] = inputString(prompt, str_len);
        }

        // Заполнение второго массива
        std::cout << "\nFilling second array:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "Enter string " + std::to_string(i + 1) + " (max " + std::to_string(str_len) + " chars): ";
            array2[i] = inputString(prompt, str_len);
        }

        // Основное меню
        while (true) {
            std::cout << "\nMenu:\n";
            std::cout << "1. Print element from first array by index\n";
            std::cout << "2. Print all elements of first array\n";
            std::cout << "3. Print element from second array by index\n";
            std::cout << "4. Print all elements of second array\n";
            std::cout << "5. Concatenate arrays element-wise\n";
            std::cout << "6. Merge arrays with duplicate removal\n";
            std::cout << "7. Exit\n";

            int choice = inputNumber("Select option: ", 1);

            try {
                switch (choice) {
                case 1: {
                    int index = inputNumber("Enter index: ", 0);
                    array1.printElement(index);
                    break;
                }
                case 2:
                    array1.printAll();
                    break;
                case 3: {
                    int index = inputNumber("Enter index: ", 0);
                    array2.printElement(index);
                    break;
                }
                case 4:
                    array2.printAll();
                    break;
                case 5: {
                    FixedLengthStringArray result = array1.concatenate(array2);
                    std::cout << "Concatenation result:\n";
                    result.printAll();
                    break;
                }
                case 6: {
                    FixedLengthStringArray result = array1.mergeUnique(array2);
                    std::cout << "Merge with duplicate removal result:\n";
                    result.printAll();
                    break;
                }
                case 7:
                    std::cout << "Exiting program.\n";
                    return 0;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}