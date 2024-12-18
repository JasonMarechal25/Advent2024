#pragma once

#include <fstream>
#include <string>
#include <ranges>
#include <boost/algorithm/string.hpp>

struct pair {
    std::vector<int> leftList;
    std::vector<int> rightList;
};


auto read_day01_input() -> pair {
    std::ifstream file("inputs/Day01/input");
    std::string line;
    std::vector<std::string> result(8);
    pair p;
    while (std::getline(file, line)) {
        boost::split(result, line, boost::is_any_of("\t "), boost::token_compress_on);
        p.leftList.push_back(std::stoi(result[0]));
        p.rightList.push_back(std::stoi(result[1]));
    }
    std::ranges::sort(p.leftList);
    std::ranges::sort(p.rightList);
    return p;
}

auto compute_distance(const pair& p) -> int {
    int distance = 0;
    for (int i = 0; i < p.leftList.size(); i++) {
        distance += std::abs(p.leftList[i] - p.rightList[i]);
    }
    return distance;
}

auto computeSimilarity(const pair& sortedPair) -> int {
    int similarity = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < sortedPair.leftList.size()) {
        if (sortedPair.leftList[leftIndex] == sortedPair.rightList[rightIndex]) {
            similarity += sortedPair.leftList[leftIndex];
            ++rightIndex;
        } else if (sortedPair.leftList[leftIndex] < sortedPair.rightList[rightIndex]) {
            ++leftIndex;
        } else { //Happens if right list smallest number is smaller than left list smallest number
            ++rightIndex;
        }
    }
    return similarity;
}