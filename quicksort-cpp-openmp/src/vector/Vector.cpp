#include "Vector.h"
#include <vector>
#include <stdlib.h>

void fillvector(std::vector<int>* vector, int val) {
  for (int i = 0; i < vector -> size(); i++) {
    vector -> at(i) = val;
  }
}

std::vector<int> makerandomvector(int size, int min, int max) {

  // e.g. 500, 400
  // e.g. 500 - 100 = 400
  int range = max - min;

  std::vector<int> rvector(size);

  for (int i = 0; i < size; i++) {
    
    // e.g. random = between 0 ... 400
    int random = rand() % range + 1;

    // e.g. between 100 ... 500
    int randomshifted = random + min;

    rvector.at(i) = randomshifted;
  }

  return rvector;
}

bool hasonlyonevalue(std::vector<int>* list) {

  int firstvalue = list -> at(0);

  // Speed through the list quickly and check if there is more than
  // one value. We don't even need a set to do this. Just set the test
  // value to the first element and check if any of the subsequent
  // elements are different. This is O(n).

  for (int i = 0; i < list -> size(); i++) {
    if (firstvalue != list -> at(i)) {
      return false;
    }
  }

  return true;
}
