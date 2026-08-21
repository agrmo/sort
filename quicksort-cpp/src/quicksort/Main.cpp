#include <iostream>
#include "Quicksort.h"
#include <ctime>
#include <stdlib.h>
#include "print/vector/Printvector.h"
#include "vector/Vector.h"
#include "timer/Timer.h"
#include "print/timer/Printtimer.h"

// Make sure to initialize the seed once per main call.
void exampleone() {
  std::vector<int> list = {0, -1, 2, -3, 1};
  std::vector<int> sorted = quicksort(list);
}

// What if the sublist is identical and the pivot achieves nothing?
void exampletwo() {
  std::vector<int> list = {-1, -1, -1, -1, -1, 4, 5, 0};
  std::vector<int> sorted = quicksort(list);
}

// Simple Quicksort with a timer.
void examplethree() {
  srand(time(NULL));
  std::vector<int> unsorted = makerandomvector(10, -5, 5);
  printvector(unsorted);
  Timer t;
  t.start();
  std::vector<int> sorted = quicksort(unsorted);
  t.stop();
  printtimerms(&t);
}

int main() {
  exampletwo();
}
