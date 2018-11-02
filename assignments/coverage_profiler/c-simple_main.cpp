
Faris A
/// @file main1.cpp
#include <iostream>

#include "coverage_map.hpp"
coverage_map_t simple_main_cpp("simple_main.cpp");
coverage_map_t foo_cpp("foo.cpp");
int main() {
  int i;
  i = 0;
  while (i < 10) {   
    ++i;   
    std::cout << i;
  }
  std::cout << '\n';
  return 0;
} 
