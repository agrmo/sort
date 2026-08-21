#include "Timer.h"
#include <iostream>

Timer::Timer() {
  // Nothing to do.
}

Timer::~Timer() {
  // Nothing to do.
}

void Timer::start() {
  clock_gettime(CLOCK_MONOTONIC, &ts_start);
}

void Timer::stop() {
  clock_gettime(CLOCK_MONOTONIC, &ts_end);
}

int Timer::get_ms() {
  float time_total_ns = (ts_end.tv_sec - ts_start.tv_sec) * 1000000000
    + (ts_end.tv_nsec - ts_start.tv_nsec);

  float time_total_ms = time_total_ns / 1000000;

  int time_total_ms_int = (int) time_total_ms;

  return time_total_ms_int;
}

int Timer::get_ns() {
  float time_total_ns = (ts_end.tv_sec - ts_start.tv_sec) * 1000000000
    + (ts_end.tv_nsec - ts_start.tv_nsec);

  int time_total_ns_int = (int) time_total_ns;

  return time_total_ns_int;
}
