#include <vector>
#include <iostream>

int main() {
    std::vector<double> numbers({7.0, 4.0, 6.0, 1.9, 10.4});

    std::cout << numbers.front() << std::endl;
    std::cout << numbers.back() << std::endl;

    numbers.emplace(numbers.begin(), 11);
    std::cout << numbers.front() << std::endl;

    std::vector<double>::iterator iterator = std::find(numbers.begin(), numbers.end(), 1.9);

    if(iterator != numbers.end()) {
        std::cout << "Number fount: " << *iterator << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }

    return 0;
}