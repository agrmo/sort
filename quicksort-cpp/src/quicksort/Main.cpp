#include <iostream>
#include "Quicksort.h"
#include <ctime>
#include <stdlib.h>
#include "print/vector/Printvector.h"

// Make sure to initialize the seed once per main call.
void exampleone() {
  srand(time(NULL));
  std::vector<int> list = {0, -1, 2, -3, 1};
  std::vector<int> sorted = quicksort(list);
}

// Simple Quicksort with a timer.
void exampletwo() {
  // srand(time(NULL));
  // std::vector<int>* list = makerandomlist(500, -500, 500);
}

int main() {
  exampleone();
}
