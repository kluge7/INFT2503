#include "equal.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int a = 10, b = 10;
    double x = 3.000001, y = 3.0;
    double z = 3.00001;
    std::string str1 = "hello", str2 = "hey";

    std::cout << "Are integers " << a << " and " << 10 << " equal? " << (equal(a, b) ? "yes" : "no") << std::endl;

    std::cout << std::fixed << std::setprecision(7);
    
    std::cout << "Are doubles " << x << " and " << y << " equal? " << (equal(x, y) ? "yes" : "no") << std::endl;
    std::cout << "Are doubles " << z << " and " << y << " equal? " << (equal(z, y) ? "yes" : "no") << std::endl;

    std::cout << "Are strings " << str1 << " and " << str2 << " equal? " << (equal(str1, str2) ? "yes" : "no") << std::endl;

    return 0;
}
