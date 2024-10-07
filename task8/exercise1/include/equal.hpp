// equal.hpp
#pragma once
#include <cmath>

template <typename Type>
bool equal(Type a, Type b) {
    return a == b;
}

bool equal(double a, double b) {
    return std::abs(a - b) < 0.00001;
}