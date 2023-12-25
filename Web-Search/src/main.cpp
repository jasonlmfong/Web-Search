#include "utils.hpp"
#include "pagerank.hpp"
#include <iostream>


int main()
{
    // matrix adj1 = { {0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}, };
    // matrix adj2 = { {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0}, };
    matrix adj = random(7);

    std::cout << "PageRank vector with damping 0.15:" << std::endl;
    column pr_score = compute_pagerank_2(adj, 0.15, 0.0001);

    for (int i = 0; i < pr_score.size(); i++)
        std::cout << pr_score[i] << std::endl;

    return 0;
}
