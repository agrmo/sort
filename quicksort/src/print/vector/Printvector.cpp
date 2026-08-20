#include <iostream>
#include <vector>
#include "Printvector.h"

void printvector(std::vector<int>* listptr) {
  std::vector<int> list = *listptr;
  printvector(list);
}

void printvector(std::vector<int> list) {

  std::cout << "[";
  
  for (int i = 0; i < list.size(); i++) {
    if (i != 0) {
      std::cout << ", ";
    }
    
    std::cout << list[i];
  }

  std::cout << "]" << std::endl;
}
