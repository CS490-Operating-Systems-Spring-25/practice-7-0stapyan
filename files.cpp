#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>

int main() {
    std::vector<std::ofstream> fileStreams;
    const int totalFiles = 100; 

    for (int i = 0; i < totalFiles; ++i) {
        std::ostringstream filename;
        filename << "file_" << i << ".txt";
        std::ofstream ofs(filename.str());
        if (!ofs.is_open()) {
            std::cerr << "Failed to open " << filename.str() << std::endl;
            break;
        }
        ofs << "This is " << filename.str() << std::endl;
        fileStreams.push_back(std::move(ofs));
    }

    std::cout << "Opened " << fileStreams.size() << " files." << std::endl;
    std::cout << "Process is now sleeping so you can inspect /proc/<pid>/fd" << std::endl;
    std::cout << "Press Ctrl+C to exit when done." << std::endl;
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }
    
    return 0;
}
