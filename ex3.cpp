#include <iostream>
#include <fstream>
#include <string>
#include <deque>

int main() {
    std::ifstream inputFile("input.txt"); 
    std::ofstream outputFile("output.txt"); 

    if (inputFile.is_open() && outputFile.is_open()) {
        std::deque<std::string> lines;
        std::string line;

        while (std::getline(inputFile, line)) {
            lines.push_front(line); 
        }

        while (!lines.empty()) {
            outputFile << lines.front() << std::endl; 
            lines.pop_front(); 
        }

        inputFile.close(); 
        outputFile.close(); 

        std::cout << "Рядки файлу були успішно переписані в інший файл зі зворотнім порядком." << std::endl;
    }
    else {
        std::cout << "Не вдалося відкрити файл." << std::endl;
    }

    return 0;
}
