#pragma once
#include <iostream>
#include <vector>

class Set {
public:
  Set();

  Set(const std::vector<int> &elements);

  void add(int element);

  bool contains(int element) const;

  Set operator+(const Set &other) const;

  Set &operator=(const Set &other);

  Set &operator+=(int element);

  friend std::ostream &operator<<(std::ostream &os, const Set &set);

private:
  std::vector<int> integers;
};
