#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

// Firstly, this will be challenging to parallelize correctly with
// OpenMP. Each level of the quicksort call will spawn two threads,
// and depending on the size and complexity of the list, we can easily
// have a call stack larger than 10, and therefore more than 2^10
// threads. So we should figure out how to tune the number of threads
// in parallel as we go along.
//
// Secondly, we unfortunately cannot return a vector by value here,
// because the recursive call will be inside a parallel block, and the
// parallel block cannot return anything, but rather overwrite a prior
// declared variable. So the best option is to make the function void,
// and pass in the unsorted list, which will then be sorted after the
// end of the call. The recursive calls will duplicate the elements in
// the list to create and sort the sublists.
//
// This problem is probably very common in parallelized functions.
void quicksort(std::vector<int>* list);

#endif
