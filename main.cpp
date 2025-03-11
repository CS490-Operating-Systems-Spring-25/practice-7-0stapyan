#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    std::ofstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        file << "Line " << i << std::endl;
        file.flush();  // Збереження даних негайно
        sleep(1);      // Затримка на 1 секунду
    }

    file.close();
    return 0;
}
