#ifndef FIXEDLENGTHSTRINGARRAY_H
#define FIXEDLENGTHSTRINGARRAY_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class FixedLengthStringArray {
private:
    std::vector<std::string> array;
    size_t string_length;

    void validateString(const std::string& str) const;

public:
    FixedLengthStringArray(size_t size, size_t str_len);

    size_t size() const;
    size_t getStringLength() const;

    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;

    FixedLengthStringArray concatenate(const FixedLengthStringArray& other) const;
    FixedLengthStringArray mergeUnique(const FixedLengthStringArray& other) const;

    void printElement(size_t index) const;
    void printAll() const;
};

#endif // FIXEDLENGTHSTRINGARRAY_H