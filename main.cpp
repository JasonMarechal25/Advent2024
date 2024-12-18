#include <iostream>
#include "day01.h"

int main() {
    pair p = read_day01_input();
    auto distance = compute_distance(p);
    std::cout << "Distance: " << distance << std::endl;
    return 0;
}
