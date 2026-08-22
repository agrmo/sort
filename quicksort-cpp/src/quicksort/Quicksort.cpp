#include "print/vector/Printvector.h"
#include "vector/Vector.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

// Pour all numbers into the left and right arrays.
// Pour all numbers equal to the pivot on the right.
void pour(std::vector<int>* list,
	  std::vector<int>* left, std::vector<int>* right,
	  int pivot) {
  
  int lefti = 0;
  int righti = 0;

  for (int i = 0; i < list -> size(); i++) {
    
    if (list -> at(i) >= pivot) {
      
      // Put in right.
      right -> at(righti) = list -> at(i);
      righti += 1;
      
    } else {

      // Put in left.
      left -> at(lefti) = list -> at(i);
      lefti += 1;
    }
  }
}

// Count the number of elements less than the pivot.
// This will be used for making the next left and right vectors.
int countleft(std::vector<int>* list, int pivot) {

  int left = 0;
  for (int i = 0; i < list -> size(); i++) {
    if (list -> at(i) < pivot) {
      left += 1;
    }
  }

  return left;
}

// Recursive Quicksort.
void quicksort(std::vector<int>* list) {

  std::cout << "Call ";
  printvector(list);

  if (list -> size() <= 1) {
    // Do nothing
    return;
  }

  if (list -> size() == 2) {
    // Compare directly and return. If the first is larger than the
    // second, swap them.
    
    if (list -> at(0) > list -> at(1)) {
      int temp = list -> at(0);
      list -> at(0) = list -> at(1);
      list -> at(1) = temp;
    }

    std::cout << "Size two, return ";
    printvector(list);
    return;
  }

  // Else, size is greater than 2.

  // The list may be entirely identical.

  // If the list has only one value, then choosing a pivot would
  // achieve nothing and the recursion would not terminate. If it's
  // identical, it's sorted, just return it.
  if (hasonlyonevalue(list)) {
    return;
  }

  // Else, the list size is greater than 2 and has at least two
  // values, e.g. [-1, -1, 6]. Go ahead and choose a pivot.
  
  int index = rand() % list -> size();
  int pivot = list -> at(index);
  std::cout << "Pivot " << index << " value " << pivot << "\n";

  int sizeleft = countleft(list, pivot);
  int sizeright = list -> size() - sizeleft;
  std::cout << "Left size " << sizeleft << ", right size " << sizeright << "\n";

  std::vector<int> left(sizeleft);
  std::vector<int> right(sizeright);
  
  // Interestingly we don't need to do any fancy memory cleanup
  // operations in this implementation. left and right will be deleted
  // at the end of the function call.

  pour(list, &left, &right, pivot);

  std::cout << "Pour left ";
  printvector(left);

  std::cout << "Pour right ";
  printvector(right);

  quicksort(&left);
  quicksort(&right);

  std::cout << "Combine left ";
  printvector(left);
  std::cout << "Combine right ";
  printvector(right);

  // What's amazing is that we don't need to make a new vector to
  // combine the two sorted lists. We can just overwrite the original
  // unsorted list. This solves the very tricky problem of how to pass
  // a pointer to the recursive function that lasts long enough to be
  // sorted, but doesn't get deleted from the stack immediately after
  // the end of the function on the way up.

  for (int i = 0; i < left.size(); i++) {
    list -> at(i) = left.at(i);
  }

  for (int i = 0; i < right.size(); i++) {
    list -> at(i + sizeleft) = right.at(i);
  }

  std::cout << "Combined ";
  printvector(list);
}
