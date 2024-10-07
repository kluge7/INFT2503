#pragma once

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 first, T2 second) : first(first), second(second) {}

    Pair operator+(const Pair &other) const {
        return Pair(first + other.first, second + other.second);
    }

    bool operator>(const Pair &other) const {
        return (first + second) > (other.first + other.second);
    }
};

