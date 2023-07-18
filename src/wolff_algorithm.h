#ifndef WOLFF_ALGORITHM_H
#define WOLFF_ALGORITHM_H

#include <vector>
#include "random_generator.h"
#include "io.h"

void add_neighbours_to_cluster(std::vector<int>& cluster, std::vector<std::vector<int>>& lattice, double T, double J, int L);
void wolff_algorithm(std::vector<std::vector<int>>& lattice, double T, int N, double J, int L, const std::string& filename, int n_autocorr);

#endif

