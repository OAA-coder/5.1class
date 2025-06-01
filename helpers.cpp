#include "helpers.h"
#include <iostream>

// ������� ��� ����� ������ ����� � ����������
// prompt - ����������� ��� �����
// minValue - ����������� ���������� ��������
int inputNumber(const std::string& prompt, int minValue) {
    int value;
    while (true) {
        std::cout << prompt;  // ������� ����������� ��� �����
        std::cin >> value;     // ��������� �������� ��������

        // ��������� ������������ �����
        if (std::cin.fail() || value < minValue) {
            std::cin.clear();  // ���������� ����� ������
            // ������� ����� ����� �� ����� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // ������� ��������� �� ������
            std::cout << "������������ ����. ����������, ������� ����� >= " << minValue << std::endl;
        }
        else {
            // ������� ����� �� ��������� ���������� ��������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;  // ���������� ���������� ��������
        }
    }
}

// ������� ��� ����� ������ � ��������� ������������ �����
// prompt - ����������� ��� �����
// maxLength - ����������� ���������� ����� ������
std::string inputString(const std::string& prompt, size_t maxLength) {
    std::string str;
    while (true) {
        std::cout << prompt;        // ������� ����������� ��� �����
        std::getline(std::cin, str); // ��������� ��� ������

        // ��������� ����� �������� ������
        if (str.length() > maxLength) {
            std::cout << "������� ������� ������. ������������ �����: "
                << maxLength << ". ����������, ���������� �����." << std::endl;
        }
        else {
            return str;  // ���������� ���������� ������
        }
    }
}