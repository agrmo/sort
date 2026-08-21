#include "print/vector/Printvector.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "vector/Vector.h"

// Pour all numbers into the left and right arrays.
// Pour any numbers equal to the pivot on the right.
void pour(std::vector<int> list,
	    std::vector<int>& left, std::vector<int>& right,
	    int pivot) {
  
  int lefti = 0;
  int righti = 0;

  for (int i = 0; i < list.size(); i++) {
    
    if (list[i] >= pivot) {
      
      // Put in right.
      right[righti] = list[i];
      righti += 1;
      
    } else {

      // Put in left.
      left[lefti] = list[i];
      lefti += 1;
    }
  }
}

// Count the number of elements less than the pivot.
// This will be used for making the next left and right vectors.
int countleft(std::vector<int> list, int pivot) {

  int left = 0;
  for (int i = 0; i < list.size(); i++) {
    if (list[i] < pivot) {
      left += 1;
    }
  }

  return left;
}

// Quicksort for int vectors.
std::vector<int> quicksort(std::vector<int> list) {

  std::cout << "Call ";
  printvector(list);

  if (list.size() <= 1) {
    // Do nothing
    return list;
  }

  if (list.size() == 2) {
    // Compare directly and return. If the first is larger than the
    // second, swap them.
    
    if (list[0] > list[1]) {
      list = {list[1], list[0]};
    }

    std::cout << "Size two, return ";
    printvector(list);
    return list;
  }

  // Else, size is greater than 2.

  // The list may be entirely identical.

  // If the list has only one value, then chosing a pivot would
  // achieve nothing and the recursion would not terminate. If it's
  // identical, it's sorted, just return it.
  if (hasonlyonevalue(list)) {
    return list;
  }

  // Else, the list size is greater than 2 and has at least two
  // values, e.g. [-1, -1, 6]. Go ahead and choose a pivot.
  
  int index = rand() % list.size();
  int pivot = list[index];
  std::cout << "Pivot " << index << " value " << pivot << "\n";

  int sizeleft = countleft(list, pivot);
  int sizeright = list.size() - sizeleft;
  std::cout << "Left size " << sizeleft << ", right size " << sizeright << "\n";

  std::vector<int> left(sizeleft);
  std::vector<int> right(sizeright);

  pour(list, left, right, pivot);

  std::cout << "Pour left ";
  printvector(left);

  std::cout << "Pour right ";
  printvector(right);
  
  std::vector<int> qleft = quicksort(left);
  std::vector<int> qright = quicksort(right);

  std::vector<int> combined(list.size());
  
  for (int i = 0; i < left.size(); i++) {
    combined[i] = qleft[i];
  }

  for (int i = 0; i < right.size(); i++) {
    combined[i + sizeleft] = qright[i];
  }

  std::cout << "Combine left ";
  printvector(qleft);
  std::cout << "Combine right ";
  printvector(qright);
  std::cout << "Combined ";
  printvector(combined);

  return combined;
}
