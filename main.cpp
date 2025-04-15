#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

int main() {
    std::ofstream ofs("test.txt", std::ios::out | std::ios::app);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open test.txt" << std::endl;
        return 1;
    }

    for (int i = 0; i < 1000; ++i) {
        ofs << "Line " << i << std::endl;
        ofs.flush();  
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    ofs.close();
    return 0;
}
