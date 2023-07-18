#ifndef IO_H
#define IO_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "random_generator.h"

void save_lattice(const std::vector<std::vector<int>>& lattice, const std::string& filename);

#endif // IO_H

