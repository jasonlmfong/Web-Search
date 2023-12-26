#pragma once

#include <vector>
#include <cmath>
#include <queue>


typedef std::vector<double> column;
typedef std::vector<std::vector<double>> matrix;


column build(double value, int size);

column operator+(column c1, column c2);

column operator-(column c1, column c2);

matrix operator+(matrix m1, matrix m2);

column operator*(double scalar, column c);

matrix operator*(double scalar, matrix m);

column operator*(matrix m, column c);

matrix transpose(matrix m);

// this can be used to get the L1 norm and the L2 norm
double norm(column& c, int norm);

matrix transition(matrix m);

matrix ones(int n);

matrix random(int size);

std::vector<int> largest_n(column res, int n);
