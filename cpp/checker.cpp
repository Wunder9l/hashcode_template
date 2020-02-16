#include "checker.h"

#include <utility>
#include <numeric>
#include <stdexcept>


i64 TChecker::CheckSolutionFromFile(const std::string& filename) {
    TSolution solution;
    ReadFromFile<TSolution>(filename, solution, ReadSolution);
    return CheckSolution(solution);
}

i64 TChecker::CheckSolution(const TSolution& solution) {
    throw std::logic_error("Not implemented");
}

