#include "lattice.h"
#include "wolff_algorithm.h"
#include "io.h"
#include <random>
#include <chrono>
#include <iostream>
#include <chrono>

int main() {
    // Initialize parameters
    int L = 40;
    double J = 1.0;
    int N_thermal = 2000;
    int N_mc = 21000;
    int n_autocorr = 5;
    double E;
    double M;
    
    // Temperatures list
    std::vector<double> temperatures = {2, 2.043, 2.086, 2.129, 2.171, 2.214, 2.257, 2.3, 2.343, 2.386, 2.429, 2.471, 2.514, 2.557, 2.6};
    
    // Initialize lattice
    std::vector<std::vector<int>> lattice;
    initialize_lattice(lattice, L);

    generator.seed(std::chrono::system_clock::now().time_since_epoch().count());

    // Loop over the list of temperatures
    for (double T : temperatures) {
        // Start time
        auto start = std::chrono::high_resolution_clock::now();

        // Create unique filename for each temperature
        std::string filename = "samples_T_" + std::to_string(T) + ".txt";
        
        // Thermalize system
        wolff_algorithm(lattice, T, N_thermal, J, L, filename, 2);
        
        // Statistics after thermalization
        E = compute_energy(lattice, J, L);
        M = compute_magnetization(lattice);
        std::cout << "After thermalization (T = " << T << ") - Energy: " << E << std::endl;
        std::cout << "After thermalization (T = " << T << ") - Magnetization: " << M << std::endl;
        
        // Sample
        wolff_algorithm(lattice, T, N_mc, J, L, filename, n_autocorr);
        
        // Statistics of last sample
        E = compute_energy(lattice, J, L);
        M = compute_magnetization(lattice);
        std::cout << "After Wolff algorithm (T = " << T << ") - Energy: " << E << std::endl;
        std::cout << "After Wolff algorithm (T = " << T << ") - Magnetization: " << M << std::endl;

        // Calculate time taken and print
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time for T = " << T << ": " << elapsed.count() << " seconds." << std::endl;
    }

    return 0;
}


