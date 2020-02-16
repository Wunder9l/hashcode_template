#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <unordered_map>
#include <functional>
#include <cassert>
#include <fstream>

using namespace std;
#define sqr(x) (x) * (x)

typedef uint64_t ui64;
typedef int64_t i64;

int distance(pair<int, int> p1, pair<int, int> p2);

template <class T>
bool ReadFromFile(const std::string& filename, T& object, std::function<bool(std::istream& input, T& object)> read) {
    std::filebuf fb;
    if (fb.open(filename, std::ifstream::in)) {
        istream input(&fb);
        if (!read(input, object)) {
            assert(("Read object from file was failed", false));
            return false;
        }
        fb.close();
    } else {
        assert(("Can not open file", false));
    }
    return true;
}

template <class T>
bool WriteToFile(const std::string& filename, const T& object, std::function<bool(std::ostream& out, const T& object)> write) {
    bool success = false;
    std::filebuf fb;
    if (fb.open(filename, std::fstream::out)) {
        ostream out(&fb);
        success = write(out, object);
        fb.close();
    } else {
        assert(("Can not open output file", false));
    }
    return success;
}