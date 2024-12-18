#include <iostream>
#include <chrono>
#include "day01.h"

class Timer {
public:
    Timer() :
            m_beg(clock_::now()) {
    }

    void reset() {
        m_beg = clock_::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<std::chrono::microseconds >(
                clock_::now() - m_beg).count();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> m_beg;
};


int main() {
    pair p = read_day01_input();
    Timer t;
    auto distance = compute_distance(p);
    std::cout << "Time: " << t.elapsed() << "us" << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    auto similarity = computeSimilarity(p);
    std::cout << "Similarity: " << similarity << std::endl;
    return 0;
}
