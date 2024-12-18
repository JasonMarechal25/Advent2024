#pragma once

#include <fstream>
#include <string>
#include <ranges>
#include <boost/algorithm/string.hpp>

struct pair {
    std::vector<int> list1;
    std::vector<int> list2;
};


auto read_day01_input() -> pair {
    std::ifstream file("inputs/Day01/input");
    std::string line;
    std::vector<std::string> result(8);
    pair p;
    while (std::getline(file, line)) {
        boost::split(result, line, boost::is_any_of("\t "), boost::token_compress_on);
        p.list1.push_back(std::stoi(result[0]));
        p.list2.push_back(std::stoi(result[1]));
    }
    std::ranges::sort(p.list1);
    std::ranges::sort(p.list2);
    return p;
}

auto compute_distance(const pair& p) -> int {
    int distance = 0;
    for (int i = 0; i < p.list1.size(); i++) {
        distance += std::abs(p.list1[i] - p.list2[i]);
    }
    return distance;
}