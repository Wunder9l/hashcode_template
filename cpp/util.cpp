#include "util.h"
#include <cmath>
#include <sstream>

int distance(pair<int, int> p1, pair<int, int> p2) {
    return (int) std::ceil(std::sqrt(sqr(p1.first - p2.first) + sqr(p1.second - p2.second)));
}
