#include "utils.hpp"


column build(double value, int size)
{
    column c_out(size);

    for (int i = 0; i < size; i++)
    {
        c_out[i] = value;
    }

    return c_out;
}


column operator+(column c1, column c2)
{
    column c_out(c1.size());

    for (int i = 0; i < c1.size(); i++)
        c_out[i] = c1[i] + c2[i];

    return c_out;
}

column operator-(column c1, column c2)
{
    column c_out(c1.size());

    for (int i = 0; i < c1.size(); i++)
        c_out[i] = c1[i] - c2[i];

    return c_out;
}


matrix operator+(matrix m1, matrix m2)
{
    matrix m_out(m1.size());

    for (int i = 0; i < m1.size(); i++)
    {
        // row
        column row(m1[0].size());

        for (int j = 0; j < m1[0].size(); j++)
            row[j] = m1[i][j] + m2[i][j];

        m_out[i] = row;
    }
    return m_out;
}


column operator*(double scalar, column c)
{
    column c_out(c.size());

    for (int i = 0; i < c.size(); i++)
        c_out[i] = c[i] * scalar;

    return c_out;
}


matrix operator*(double scalar, matrix m)
{
    matrix m_out(m.size());

    for (int i = 0; i < m.size(); i++)
    {
        // row
        column row(m[0].size());

        for (int j = 0; j < m[0].size(); j++)
            row[j] = m[i][j] * scalar;

        m_out[i] = row;
    }
    return m_out;
}


column operator*(matrix m, column c)
{
    column c_out(c.size());

    for (int i = 0; i < m.size(); i++)
    {
        double sum = 0;

        for (int j = 0; j < c.size(); j++)
            sum += m[i][j] * c[j];

        c_out[i] = sum;
    }

    return c_out;
}

matrix transpose(matrix m)
{
    matrix m_out(m.size());

    for (int i = 0; i < m.size(); i++)
    {
        column row(m.size());

        for (int j = 0; j < m.size(); j++)
            row[j] = m[j][i];

        m_out[i] = row;
    }
    return m_out;
}

// this can be used to get the L1 norm and the L2 norm
double norm(column& c, int norm)
{
    double sum = 0;

    for (int i = 0; i < c.size(); i++)
        sum += std::pow(c[i], norm);

    return std::pow(sum, 1.0 / norm);
}


// return the transition matrix of a given adjacency matrix
matrix transition(matrix m)
{
    // this should be a square matrix
    int n = m.size();

    matrix m_out = m;

    for (int j = 0; j < n; j++)
    {
        int out = 0;
        for (int i = 0; i < n; i++)
            out += m[i][j];
        if (out == 0)
            continue;
        for (int i = 0; i < n; i++)
            if (m[i][j] == 1)
                m_out[i][j] /= out;
    }

    return m_out;
}


matrix ones(int n)
{
    matrix m_out(n);

    for (int i = 0; i < n; i++)
    {
        column row(n);
        for (int j = 0; j < n; j++)
            row[j] = 1;

        m_out[i] = row;
    }

    return m_out;
}


matrix random(int size)
{
    matrix m_out(size);

    for (int i = 0; i < size; i++)
    {
        column row(size);
        for (int j = 0; j < size; j++)
            row[j] = rand() % 2;

        m_out[i] = row;
    }

    return m_out;
}

#include <iostream>
std::vector<int> largest_n(column res, int n)
{
    std::priority_queue<std::pair<double, int>> heap;

    for (int i = 0; i < res.size(); i++)
        heap.push(std::pair<double, int>(res[i], i + 1));

    std::vector<int> top;
    int count = 0;
    while (!heap.empty() && count < n)
    {
        top.push_back(heap.top().second);
        heap.pop();
        count += 1;
    }

    return top;
}
