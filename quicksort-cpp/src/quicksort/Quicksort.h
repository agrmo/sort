#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

// Quicksort for a list of integers.  We will allow duplicate integers
// to live in the list.  This means that there is an extra base case:
// - Size 0, return
// - Size 1, return
// - Size 2, manual sort and return
// - Size 3,
//   - If identical values: return
//   - If not identical: recurse
//
// This makes things a bit more expensive but there isn't a way to
// chop up the array if the pivot achieves nothing on a list of
// identical numbers.
std::vector<int> quicksort(std::vector<int> list);

#endif
