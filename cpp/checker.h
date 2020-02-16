#pragma once

#include <utility>

#include "models.h"
#include "solution.h"
#include "util.h"

class TChecker {
public :
    TChecker(TEnvironment environment) : Environment(std::move(environment)) {}

    i64 CheckSolution(const TSolution& solution);
    i64 CheckSolutionFromFile(const std::string& filename);

protected:
    TEnvironment Environment;
};


