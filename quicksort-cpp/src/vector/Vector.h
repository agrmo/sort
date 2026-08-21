#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

// Helper functions for vectors.

// This should be a template.
void fillvector(std::vector<int>* vector, int val);

// Make a vector and fill it with random values between min and max.
// Pass by value.
// Assuming the random seed is already set.
std::vector<int> makerandomvector(int size, int min, int max);

// Is the vector a list of only one value?
bool hasonlyonevalue(std::vector<int>& list);

#endif
