#include "Set.hpp"
#include <iostream>
#include <vector>

int main() { 
  std::vector<int> vector1 = {1, 4, 3};
  Set set1(vector1);

  std::vector<int> vector2 = {4, 7};
  Set set2(vector2);

  Set set3 = set1 + set2;
  std::cout << "union av " << set1 << " og " << set2 << " blir " << set3 << std::endl;

  Set set4 = set3;
  set4 += 10;
  std::cout << "når vi legger til " << 10 << " til set " << set3 << " blir det " << set4 << std::endl;
}