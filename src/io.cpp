#include "io.h"
#include <fstream>

void save_lattice(const std::vector<std::vector<int>>& lattice, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);  // Open file in append mode
    if (file.is_open()) {
        for (const auto& row : lattice) {
            for (int spin : row) {
                file << spin << ' ';
            }
        }
        file << "\n";
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

