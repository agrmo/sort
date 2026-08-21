#include <iostream>
#include <vector>
#include "print/vector/Printvector.h"
#include "print/pointervector/Printpointervector.h"
#include "Vector.h"

// What happens if we are passed a vector directly and try to modify it
void tryeditdirect(std::vector<int> v) {
  std::cout << "this array has addr " << &v << "\n";
  v[0] = -1;
  v[1] = -5;
}

// What happens if we are passed a vector reference and try to modify it
void tryeditreference(std::vector<int>& v) {
  std::cout << "this array has addr " << &v << "\n";
  v[0] = -1;
  v[1] = -3;
}

// What happens if we are passed a vector pointer and try to modify it
void tryeditpointer(std::vector<int>* v) {
  std::cout << "this array has addr " << v << "\n";
  v->at(0) = -1;
  v->at(1) = -3;
}

// Try to pass a vector into another function, edit it, and print it.
void trypassdirect() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  printvector(va); // 2 3
  tryeditdirect(va);
  printvector(va); // still 2 3
}

// Try to pass a vector reference into another function, edit it, and print it.
void trypassreference() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  printvector(va); // 2 3
  tryeditreference(va);
  printvector(va); // -1 -3
}

// Try to pass a vector pointer into another function, edit it, and print it.
void trypasspointer() {
  std::vector<int> va = {2,3};
  std::cout << "this array has addr " << &va << "\n";
  printvector(va); // 2 3
  tryeditpointer(&va);
  printvector(va); // -1 -3
}

// Initialize a vector then add values later.
void tryaddlater() {
  std::vector<int> zahlen(3);
  printvector(zahlen);
  zahlen = {3,4,5};
  printvector(zahlen);
}

// Initialize a vector, then initialize another vector with its values.
// Then try editing the first vector.
void tryeditlater() {
  std::vector<int> za = {1,2,3};
  std::vector<int> zb = za;
  za.at(0) = -1;

  printvector(zb); // {1,2,3}
}

// Initialize a vector of int pointers, then initialize another vector
// pointing with the first. Then delete the first.
void tryeditpointerslater() {

  std::vector<int> za(0);
  std::vector<int*> zb(0);

  for (int i = 0; i < 5; i++) {
    za.push_back(i);
    zb.push_back(&(za.at(i)));
  }

  printvector(za); // [0,1,2,3,4]
  printpointervector(zb); // [bad,bad,bad,bad,4]

  // Why doesn't this work? The vector was increased in size and the
  // memory was moved around.
}

// Initialize a fixed size vector of int pointers, then initialize
// another vector pointing with the first. Then delete the first.
void tryeditpointerslaterfixed() {

  int size = 5;
  std::vector<int> za(size);
  std::vector<int*> zb(size);

  for (int i = 0; i < size; i++) {
    za.at(i) = i;
    zb.at(i) = &(za.at(i));
  }

  printvector(za); // [0,1,2,3,4]
  printpointervector(zb); // [0,1,2,3,4]

  // Works now. Try editing za.

  za.at(0) = -1;
  printpointervector(zb); // [-1,1,2,3,4]
}

void exampleone() {
  std::vector<int> rvector = makerandomvector(20, -10, 10);
  printvector(rvector);
}

int main() {
  exampleone();
}
