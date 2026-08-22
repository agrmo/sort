#ifndef TIMER_H
#define TIMER_H

#include <time.h>

// A basic timer.

class Timer {

  struct timespec ts_start, ts_end;
  
public:
  Timer();
  ~Timer();

  // Start the timer.
  void start();

  // Stop the timer.
  void stop();

  // Get the duration in milliseconds
  int get_ms();

  // Get the duration in nanoseconds.
  int get_ns();
};

#endif
