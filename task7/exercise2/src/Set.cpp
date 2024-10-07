#include "Set.hpp"
#include <algorithm>

Set::Set() = default;

Set::Set(const std::vector<int>& elements) {
    for (int element : elements) {
        add(element);
    }
}

void Set::add(int element) {
    if (!contains(element)) {  
        integers.push_back(element);
    }
}

bool Set::contains(int element) const {
    return std::find(integers.begin(), integers.end(), element) != integers.end();
}

Set Set::operator+(const Set& other) const {
    Set result = *this;
    for (int element : other.integers) {
        result.add(element);
    }
    return result;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) { 
        integers = other.integers;
    }
    return *this;
}

Set& Set::operator+=(int element) {
    add(element);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Set& set) {
    for (int element : set.integers) {
        os << element << " ";
    }
    return os;
}
