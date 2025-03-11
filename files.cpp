#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>

int main() {
    std::vector<std::ofstream> files;
    for (int i = 0; i < 1000; ++i) {
        std::string filename = "file_" + std::to_string(i) + ".txt";
        files.emplace_back(filename);
        if (!files.back().is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return 1;
        }
        sleep(1);  // Затримка на 1 секунду
    }

    for (auto& file : files) {
        file.close();
    }

    return 0;
}
