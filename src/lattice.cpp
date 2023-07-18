#include "lattice.h"
#include <random>
#include <vector>
#include <chrono>

void initialize_lattice(std::vector<std::vector<int>>& lattice, int L) {
    std::uniform_int_distribution<int> distribution(0, 1);
    for(int i=0; i<L; i++){
        std::vector<int> row;
        for(int j=0; j<L; j++){
            row.push_back(distribution(generator) * 2 - 1);
        }
        lattice.push_back(row);
    }
}

double compute_energy(std::vector<std::vector<int>>& lattice, double J, int L) {
    double E = 0.0;
    for(int i=0; i<L; i++){
        for(int j=0; j<L; j++){
            E -= J * lattice[i][j] * (lattice[(i+1)%L][j] + lattice[i][(j+1)%L]
                + lattice[(i-1+L)%L][j] + lattice[i][(j-1+L)%L]);
        }
    }
    return E/2;
}

double compute_magnetization(std::vector<std::vector<int>>& lattice) {
    double M = 0.0;
    for(auto& row : lattice){
        for(auto& el : row){
            M += el;
        }
    }
    return M;
}
