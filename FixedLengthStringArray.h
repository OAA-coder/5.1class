#ifndef FIXEDLENGTHSTRINGARRAY_H  // Защита от повторного включения заголовочного файла
#define FIXEDLENGTHSTRINGARRAY_H  // Установка макроса для защиты включения

#include <string>      // Для работы со строками std::string
#include <vector>      // Для использования std::vector как базовой структуры данных
#include <stdexcept>   // Для исключений (например, std::out_of_range)
#include <iostream>   // Для вывода в консоль (std::cout)

class FixedLengthStringArray {
private:
    std::vector<std::string> array;  // Вектор для хранения строк фиксированной длины
    size_t string_length;            // Фиксированная длина строк в массиве

    // Проверяет, соответствует ли строка заданной длине
    // Выбрасывает исключение, если длина не совпадает
    void validateString(const std::string& str) const;

public:
    // Конструктор: создает массив заданного размера с фиксированной длиной строк
    FixedLengthStringArray(size_t size, size_t str_len);

    // Возвращает текущий размер массива (количество строк)
    size_t size() const;

    // Возвращает зафиксированную длину строк в массиве
    size_t getStringLength() const;

    // Оператор доступа к строке по индексу (неконстантная версия)
    std::string& operator[](size_t index);

    // Оператор доступа к строке по индексу (константная версия)
    const std::string& operator[](size_t index) const;

    // Конкатенация двух массивов (возвращает новый массив)
    FixedLengthStringArray concatenate(const FixedLengthStringArray& other) const;

    // Слияние двух массивов с удалением дубликатов (возвращает новый массив)
    FixedLengthStringArray mergeUnique(const FixedLengthStringArray& other) const;

    // Вывод элемента с заданным индексом в консоль
    void printElement(size_t index) const;

    // Вывод всех элементов массива в консоль
    void printAll() const;
};

#endif // FIXEDLENGTHSTRINGARRAY_H  // Конец заголовочного файла