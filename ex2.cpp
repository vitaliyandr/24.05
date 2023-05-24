#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("input.txt"); // Відкриття вхідного файлу для читання
    std::ofstream outputFile("output.txt"); // Відкриття вихідного файлу для запису

    if (inputFile.is_open() && outputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            outputFile << line << std::endl; // Запис рядка у вихідний файл з переносом рядка
        }

        inputFile.close(); // Закриття вхідного файлу
        outputFile.close(); // Закриття вихідного файлу

        std::cout << "Рядки файлу були успішно переписані в інший файл." << std::endl;
    }
    else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }

    return 0;
}
