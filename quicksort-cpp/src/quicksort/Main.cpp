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
  quicksort(&list);
}

// What if the sublist is identical and the pivot achieves nothing?
void exampletwo() {
  std::vector<int> list = {-1, -1, -1, -1, -1, 4, 5, 0};
  quicksort(&list);
}

// Simple Quicksort with a timer.
void examplethree() {
  srand(time(NULL));
  std::vector<int> list = makerandomvector(15, -5, 5);
  printvector(list);
  Timer t;
  t.start();
  quicksort(&list);
  t.stop();
  printtimerms(&t);
}

int main() {
  examplethree();
}
