#pragma once

#include "models.h"


struct TSolution {
};


bool ReadSolution(std::istream& input, TSolution& solution);
bool WriteSolution(std::ostream& out, const TSolution& solution);