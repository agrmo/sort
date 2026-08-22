#include <iostream>
#include <vector>
#include "Timer.h"
#include "vector/Vector.h"
#include "print/timer/Printtimer.h"

int main() {
  // Fill an array with a particular value and time it.
  Timer t;
  t.start();
  std::vector<int> a(5);
  fillvector(&a, 123);
  t.stop();
  printtimerns(&t);
}
