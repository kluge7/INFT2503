#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  std::vector<int> v2 = {2, 3, 12, 14, 24};

  bool are_equal1 = std::equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int a, int b) {
    return std::abs(a - b) <= 2;
  });

  bool are_equal2 = std::equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int a, int b) {
    return std::abs(a - b) <= 2;
  });

  if(are_equal1) {
    std::cout << "The five first element in v1 are approximately equal to those in v2" << std::endl;
  } else {
    std::cout << "The five first element in v1 are NOT approximately equal to those in v2" << std::endl;
  }


  if(are_equal2) {
    std::cout << "The four first element in v1 are approximately equal to those in v2" << std::endl;
  } else {
    std::cout << "The four first element in v1 are NOT approximately equal to those in v2" << std::endl;
  }

  return 0;
}
