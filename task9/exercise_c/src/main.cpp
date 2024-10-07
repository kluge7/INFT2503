#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int main() {
  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  std::vector<int> v3(v1.size());

  std::replace_copy_if (v1.begin(), v1.end(), v3.begin(), [](int n){
    return n % 2 != 0;
  }, 100);

  std::cout << "Before replacing odds with 100: ";
  for (int n : v1) {
      std::cout << n << " ";
  }
  std::cout << std::endl;

  std::cout << "After replacing odds with 100: ";
  for (int n : v3) {
      std::cout << n << " ";
  }
  std::cout << std::endl;

  return 0;
}