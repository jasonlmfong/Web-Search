#include "utils.hpp"
#include "pagerank.hpp"
#include "hits.hpp"
#include <iostream>


int main()
{
    // matrix adj1 = { {0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {0, 0, 1, 1, 0}, };
    // matrix adj2 = { {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0}, };
    matrix adj = random(50);

    column pr_score = compute_pagerank_2(adj, 0.15, 0.0001);

    std::cout << "PageRank vector with damping 0.15:" << std::endl;
    for (int i = 0; i < pr_score.size(); i++)
        std::cout << pr_score[i] << std::endl;

    std::cout << "PageRank will select the following as the top sites" << std::endl;
    std::vector<int> pr_top = largest_n(pr_score, 10);
    for (int i = 0; i < pr_top.size(); i++)
        std::cout << pr_top[i] << " ";
    std::cout << std::endl;


    std::pair<column, column> hits_res = compute_hits(adj, 0.0001, 100);

    std::cout << "HITS authority vector:" << std::endl;
    for (int i = 0; i < hits_res.first.size(); i++)
        std::cout << hits_res.first[i] << std::endl;
    std::cout << "HITS authority vector:" << std::endl;
    for (int i = 0; i < hits_res.second.size(); i++)
        std::cout << hits_res.second[i] << std::endl;

    std::cout << "HITS will select the following as the top authority sites" << std::endl;
    std::vector<int> auth_top = largest_n(hits_res.first, 10);
    for (int i = 0; i < auth_top.size(); i++)
        std::cout << auth_top[i] << " ";
    std::cout << std::endl;

    return 0;
}
