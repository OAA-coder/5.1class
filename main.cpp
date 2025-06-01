#include "FixedLengthStringArray.h"
#include "helpers.h"
#include <iostream>
#include <stdexcept>

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "���������������� ���������: ������ ����� ������������� �����\n";

    try {
        // ������� ��� ������� ��� ������������
        int size = inputNumber("������� ������ ��������: ");
        int str_len = inputNumber("������� ������������ ����� �����: ");

        // ������������� ��������
        FixedLengthStringArray array1(size, str_len);
        FixedLengthStringArray array2(size, str_len);

        // ���������� ������� �������
        std::cout << "\n���������� ������� �������:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "������� ������ " + std::to_string(i + 1) +
                " (����. " + std::to_string(str_len) + " ��������): ";
            array1[i] = inputString(prompt, str_len);
        }

        // ���������� ������� �������
        std::cout << "\n���������� ������� �������:\n";
        for (int i = 0; i < size; ++i) {
            std::string prompt = "������� ������ " + std::to_string(i + 1) +
                " (����. " + std::to_string(str_len) + " ��������): ";
            array2[i] = inputString(prompt, str_len);
        }

        // �������� ���� ���������
        while (true) {
            std::cout << "\n����:\n";
            std::cout << "1. ������� ������� ������� ������� �� �������\n";
            std::cout << "2. ������� ��� �������� ������� �������\n";
            std::cout << "3. ������� ������� ������� ������� �� �������\n";
            std::cout << "4. ������� ��� �������� ������� �������\n";
            std::cout << "5. ���������� ������� �����������\n";
            std::cout << "6. ���������� ������� � ��������� ����������\n";
            std::cout << "7. �����\n";

            int choice = inputNumber("�������� ����� ����: ", 1);

            try {
                switch (choice) {
                case 1: {
                    // ����� �������� ������� ������� �� �������
                    int index = inputNumber("������� ������: ", 0);
                    array1.printElement(index);
                    break;
                }
                case 2:
                    // ����� ���� ��������� ������� �������
                    array1.printAll();
                    break;
                case 3: {
                    // ����� �������� ������� ������� �� �������
                    int index = inputNumber("������� ������: ", 0);
                    array2.printElement(index);
                    break;
                }
                case 4:
                    // ����� ���� ��������� ������� �������
                    array2.printAll();
                    break;
                case 5: {
                    // ������������ ��������
                    FixedLengthStringArray result = array1.concatenate(array2);
                    std::cout << "��������� �����������:\n";
                    result.printAll();
                    break;
                }
                case 6: {
                    // ������� �������� � ��������� ����������
                    FixedLengthStringArray result = array1.mergeUnique(array2);
                    std::cout << "��������� ������� � ��������� ����������:\n";
                    result.printAll();
                    break;
                }
                case 7:
                    // ����� �� ���������
                    std::cout << "���������� ���������.\n";
                    return 0;
                default:
                    std::cout << "�������� �����. ���������� �����.\n";
                }
            }
            catch (const std::exception& e) {
                // ��������� ������ � ��������� ����
                std::cerr << "������: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        // ��������� ����������� ������ �������������
        std::cerr << "����������� ������: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}