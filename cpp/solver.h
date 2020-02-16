#pragma once


#include "models.h"
#include "solution.h"
#include <vector>

class TSolver {
public:
    TSolver(TEnvironment env);
    TSolution Solve();

    TEnvironment Env;
};
