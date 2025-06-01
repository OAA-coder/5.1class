#ifndef HELPERS_H       // ��������, �� ��� �� ���� ������������ ���� ��� ���������
#define HELPERS_H       // ����������� �������, ����� ������������� ��������� ���������

#include <iostream>     // ��� ������ � ������/������� (std::cin, std::cout)
#include <limits>      // ��� ������ � ��������� �������� ����� (std::numeric_limits)
#include <string>      // ��� ������ �� �������� (std::string)

// ������� ��� ����� ������ ����� � ��������� ���������
int inputNumber(const std::string& prompt, int minValue = 1);

// ������� ��� ����� ������ � ��������� ������������ �����
std::string inputString(const std::string& prompt, size_t maxLength);

#endif     // ����� ������� �������������