#include <iostream>
#include "timer/Timer.h"
#include "Printtimer.h"

void printtimerms(Timer* t) {
  int dur_ms = t -> get_ms();
  std::cout << "Duration: " << dur_ms << " ms \n";
}

void printtimerns(Timer* t) {
  int dur_ns = t -> get_ns();
  std::cout << "Duration: " << dur_ns << " ns \n";
}
