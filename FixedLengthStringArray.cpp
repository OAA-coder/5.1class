#include "FixedLengthStringArray.h"
#include <algorithm>
#include <iostream>
using namespace std;
void FixedLengthStringArray::validateString(const std::string& str) const {
    if (str.length() > string_length) {
        throw std::invalid_argument("String length exceeds maximum allowed length");
    }
}

FixedLengthStringArray::FixedLengthStringArray(size_t size, size_t str_len) : string_length(str_len) {
    if (size == 0 || str_len == 0) {
        throw std::invalid_argument("Size and string length must be positive");
    }
    array.resize(size);
}

size_t FixedLengthStringArray::size() const {
    return array.size();
}

size_t FixedLengthStringArray::getStringLength() const {
    return string_length;
}

std::string& FixedLengthStringArray::operator[](size_t index) {
    if (index >= array.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

const std::string& FixedLengthStringArray::operator[](size_t index) const {
    if (index >= array.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

FixedLengthStringArray FixedLengthStringArray::concatenate(const FixedLengthStringArray& other) const {
    if (array.size() != other.size()) {
        throw std::invalid_argument("Arrays must be of the same size");
    }

    FixedLengthStringArray result(array.size(), string_length + other.string_length);
    for (size_t i = 0; i < array.size(); ++i) {
        result[i] = array[i] + other[i];
    }
    return result;
}

FixedLengthStringArray FixedLengthStringArray::mergeUnique(const FixedLengthStringArray& other) const {
    if (string_length != other.string_length) {
        throw std::invalid_argument("String lengths must be equal");
    }

    std::vector<std::string> uniqueElements = array;
    uniqueElements.insert(uniqueElements.end(), other.array.begin(), other.array.end());

    std::sort(uniqueElements.begin(), uniqueElements.end());
    auto last = std::unique(uniqueElements.begin(), uniqueElements.end());
    uniqueElements.erase(last, uniqueElements.end());

    FixedLengthStringArray result(uniqueElements.size(), string_length);
    for (size_t i = 0; i < uniqueElements.size(); ++i) {
        result[i] = uniqueElements[i];
    }
    return result;
}

void FixedLengthStringArray::printElement(size_t index) const {
    std::cout << "Element at index " << index << ": " << array[index] << std::endl;
}

void FixedLengthStringArray::printAll() const {
    std::cout << "Array contents (" << array.size() << " elements, max length " << string_length << "):\n";
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << "[" << i << "]: " << array[i] << std::endl;
    }
}