#include "wolff_algorithm.h"
#include "lattice.h"
#include <random>
#include <chrono>
#include <iostream>

std::uniform_real_distribution<double> distribution(0.0, 1.0);	

void add_neighbours_to_cluster(std::vector<std::pair<int,int>>& cluster, std::vector<std::vector<int>>& lattice, double T, int s, double J, int L) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    std::vector<std::pair<int,int>> neighbours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    std::pair<int,int> curr_pos = cluster.back();
    cluster.pop_back();
    for(auto& n : neighbours) {
        int x = (curr_pos.first + n.first + L) % L;
        int y = (curr_pos.second + n.second + L) % L;
        int aligned = s * lattice[x][y];
        if(aligned == 1) {
            double p = 1 - std::exp(-2 * J/ T);
            if(distribution(generator) <= p) {
                lattice[x][y] *= -1;
                cluster.push_back(std::make_pair(x, y));
            }
        }
    }
}

void wolff_algorithm(std::vector<std::vector<int>>& lattice, double T, int N, double J, int L, const std::string& filename, int n_autocorr) {
    // Create file with truncate
    std::ofstream file(filename, std::ios::trunc);
    file.close();
    
    std::uniform_int_distribution<int> distribution(0, L-1);
    
    // Loop for samples
    for(int i=0; i<N; i++) {
        
        // Prevent autocorrelation
        for(int j=0; j<n_autocorr; j++){
            
            // Perform single Wolff step
            std::vector<std::pair<int,int>> cluster = {std::make_pair(distribution(generator), distribution(generator))};
            int s = lattice[cluster.back().first][cluster.back().second];
            lattice[cluster.back().first][cluster.back().second] *= -1;
            while(!cluster.empty()) {
                add_neighbours_to_cluster(cluster, lattice, T, s, J, L);
            }
            
        }
        // Store lattice configuration
        save_lattice(lattice, filename);
        
        if(i % 1000 == 0){
            float iN = 100 * float(i) / float(N);
            std::cout << "Progress: " << iN << " %" << std::endl;
        }
    }
}
