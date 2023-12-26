#pragma once

#include "utils.hpp"


column compute_pagerank_1(matrix adjacency_matrix, const double damp, const double error);

column compute_pagerank_2(matrix adjacency_matrix, const double damp, const double error);
