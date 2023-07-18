// random_generator.cpp
#include "random_generator.h"

std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

