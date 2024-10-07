#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};

  auto it = find_if(v1.begin(), v1.end(), [](int n) {
    return n > 15;
  });

  if(it != v1.end()) {
    int index = std::distance(v1.begin(), it);
    std::cout << "The first element in v1 that is larger than 15 is at index " << index << std::endl;
  }

  return 0;
}
