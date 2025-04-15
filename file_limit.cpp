#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>

int main() {
    const int batchSize = 1000;
    const int totalFiles = 15000;
    std::vector<std::ofstream*> openFiles;
    
    for (int i = 0; i < totalFiles; ++i) {
        std::ostringstream filename;
        filename << "limit_file_" << i << ".txt";
        std::ofstream* ofs = new std::ofstream(filename.str());
        if (!ofs->is_open()) {
            std::cerr << "Failed to open file: " << filename.str() << std::endl;
            delete ofs;
            break;
        }
        openFiles.push_back(ofs);
        
        if ((i + 1) % batchSize == 0) {
            std::cout << "Opened " << (i + 1) << " files. Sleeping for 1 second." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    
    std::cout << "Finished opening files or reached file descriptor limit." << std::endl;
    std::cout << "Press Enter to close all files and exit." << std::endl;
    std::cin.get();
    
    for (auto ofs : openFiles) {
        ofs->close();
        delete ofs;
    }
    
    return 0;
}
