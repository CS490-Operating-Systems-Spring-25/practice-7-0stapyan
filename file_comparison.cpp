#include <iostream>
#include <fstream>
#include <string>

void compareFiles(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Error: One or both files could not be opened." << std::endl;
        return;
    }

    std::string line1, line2;
    int lineNumber = 1;

    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            std::cout << "Files differ at line " << lineNumber << ":" << std::endl;
            std::cout << "File 1: " << line1 << std::endl;
            std::cout << "File 2: " << line2 << std::endl;
            return;
        }
        lineNumber++;
    }

    if (f1.eof() && f2.eof()) {
        std::cout << "Files are identical." << std::endl;
    } else {
        std::cout << "Files have different lengths." << std::endl;
    }
}

int main() {
    std::string file1, file2;
    std::cout << "Enter the first file name: ";
    std::cin >> file1;
    std::cout << "Enter the second file name: ";
    std::cin >> file2;

    compareFiles(file1, file2);

    return 0;
}
