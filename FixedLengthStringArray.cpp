#include "FixedLengthStringArray.h"
#include <algorithm>  // Для использования sort, unique
#include <iostream>
using namespace std;

// Проверяет, что длина строки не превышает допустимую
void FixedLengthStringArray::validateString(const std::string& str) const {
    if (str.length() > string_length) {
        throw std::invalid_argument("Длина строки превышает максимально допустимую");
    }
}

// Конструктор: создает массив строк заданного размера с фиксированной длиной
FixedLengthStringArray::FixedLengthStringArray(size_t size, size_t str_len) : string_length(str_len) {
    if (size == 0 || str_len == 0) {
        throw std::invalid_argument("Размер и длина строки должны быть положительными");
    }
    array.resize(size);
}

// Возвращает количество элементов в массиве
size_t FixedLengthStringArray::size() const {
    return array.size();
}

// Возвращает зафиксированную длину строк
size_t FixedLengthStringArray::getStringLength() const {
    return string_length;
}

// Оператор доступа для изменения элемента по индексу
std::string& FixedLengthStringArray::operator[](size_t index) {
    if (index >= array.size()) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    return array[index];
}

// Оператор доступа для чтения элемента по индексу
const std::string& FixedLengthStringArray::operator[](size_t index) const {
    if (index >= array.size()) {
        throw std::out_of_range("Индекс выходит за границы массива");
    }
    return array[index];
}

// Объединяет строки двух массивов в новый массив
FixedLengthStringArray FixedLengthStringArray::concatenate(const FixedLengthStringArray& other) const {
    if (array.size() != other.size()) {
        throw std::invalid_argument("Массивы должны быть одинакового размера");
    }

    FixedLengthStringArray result(array.size(), string_length + other.string_length);
    for (size_t i = 0; i < array.size(); ++i) {
        result[i] = array[i] + other[i];
    }
    return result;
}

// Объединяет два массива, удаляя дубликаты
FixedLengthStringArray FixedLengthStringArray::mergeUnique(const FixedLengthStringArray& other) const {
    if (string_length != other.string_length) {
        throw std::invalid_argument("Длины строк должны совпадать");
    }

    // Собираем все элементы из обоих массивов
    std::vector<std::string> uniqueElements = array;
    uniqueElements.insert(uniqueElements.end(), other.array.begin(), other.array.end());

    // Сортируем и удаляем дубликаты
    std::sort(uniqueElements.begin(), uniqueElements.end());
    auto last = std::unique(uniqueElements.begin(), uniqueElements.end());
    uniqueElements.erase(last, uniqueElements.end());

    // Создаем новый массив с уникальными элементами
    FixedLengthStringArray result(uniqueElements.size(), string_length);
    for (size_t i = 0; i < uniqueElements.size(); ++i) {
        result[i] = uniqueElements[i];
    }
    return result;
}

// Выводит в консоль элемент с указанным индексом
void FixedLengthStringArray::printElement(size_t index) const {
    std::cout << "Элемент с индексом " << index << ": " << array[index] << std::endl;
}

// Выводит в консоль все элементы массива
void FixedLengthStringArray::printAll() const {
    std::cout << "Содержимое массива (" << array.size()
        << " элементов, максимальная длина " << string_length << "):\n";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << "[" << i << "]: " << array[i] << std::endl;
    }
}