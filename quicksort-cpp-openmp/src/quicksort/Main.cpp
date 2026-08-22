#include "Quicksort.h"
#include "print/timer/Printtimer.h"
#include "print/vector/Printvector.h"
#include "timer/Timer.h"
#include "vector/Vector.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

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
  int size = 100000;
  int min = -5000;
  int max = 5000;
  printf("Quicksort random list size %d min %d max %d\n", size, min, max);
  std::vector<int> list = makerandomvector(size, min, max);
  Timer t;
  t.start();
  quicksort(&list);
  t.stop();
  printtimerms(&t);
}

int main() {
  examplethree();
}
