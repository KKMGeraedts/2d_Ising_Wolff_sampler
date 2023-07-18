#ifndef LATTICE_H
#define LATTICE_H

#include <vector>
#include "random_generator.h"

void initialize_lattice(std::vector<std::vector<int>>& lattice, int L);
double compute_energy(std::vector<std::vector<int>>& lattice, double J, int L);
double compute_magnetization(std::vector<std::vector<int>>& lattice);

#endif

