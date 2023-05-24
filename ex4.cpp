#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt"); // Відкриття вхідного файлу для читання
    std::ofstream outputFile("output.txt"); // Відкриття вихідного файлу для запису

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        std::string lastLineWithoutSpace;
        bool hasLineWithoutSpace = false;

        while (std::getline(inputFile, line)) {
            if (line.find(' ') == std::string::npos) {
                lastLineWithoutSpace = line; // Запам'ятовуємо останній рядок без пробілу
                hasLineWithoutSpace = true;
            }
            outputFile << line << std::endl; // Запис рядка у вихідний файл з переносом рядка
        }

        if (hasLineWithoutSpace) {
            outputFile << "------------" << std::endl; // Додавання рядка з рисками
        } else {
            outputFile << std::endl << "------------" << std::endl; // Додавання рядка з рисками після всіх рядків
        }

        inputFile.close(); // Закриття вхідного файлу
        outputFile.close(); // Закриття вихідного файлу

        std::cout << "Рядок з рисками був успішно доданий до файлу." << std::endl;
    } else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }

    return 0;
}
