#pragma once
#include <chrono>

class Timer {
public:
  Timer() {
    start(); // Start timer upon construction
  }

  void start() {
    start_time = std::chrono::high_resolution_clock::now();
  }

  double elapsed_time() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return elapsed.count() / 1000.0; // Convert to milliseconds
  }

  void reset() {
    start_time = std::chrono::high_resolution_clock::now();
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};
