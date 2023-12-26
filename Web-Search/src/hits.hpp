#pragma once

#include "utils.hpp"


std::pair<column, column> compute_hits(matrix adjacency_matrix, const double error, int max_iterations);
