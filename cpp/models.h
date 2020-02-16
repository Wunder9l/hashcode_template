#pragma once

#include "util.h"
#include <iostream>
#include <cassert>
#include <unordered_set>
#include "constants.h"


struct TEnvironment {
    TConstantStorage Constants;
};

bool ReadEnvironment(std::istream& input, TEnvironment& env);