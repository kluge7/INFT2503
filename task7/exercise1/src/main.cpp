//
// fraction/main.cpp
//
#include "fraction.hpp"
#include <iostream>
#include <string>

void print(const std::string &text, const Fraction &broek) {
  std::cout << text << broek.numerator << " / " << broek.denominator << std::endl;
}

int main() {
  Fraction fraction1(2, 3);

  Fraction fraction2 = fraction1 - 5;
  Fraction fraction3 = 5 - fraction1;

  print("fraction1 = ", fraction1);
  print("fraction1 - 5 = ", fraction2);
  print("5 - fraction1 = ", fraction3);
}