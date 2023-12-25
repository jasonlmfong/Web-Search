#include "pagerank.hpp"


column compute_pagerank_1(matrix adjacency_matrix, const double damp, const double error)
{
    int size = adjacency_matrix.size();

    matrix transition_matrix = transition(adjacency_matrix);

    matrix pagerank = (1 - damp) * transition_matrix + (damp / size) * ones(size);

    double prob = 1.0 / size;
    column score = build(prob, size);

    double difference_norm = norm(score, 2);

    // continue until the score stabilizes
    while (difference_norm > error)
    {
        column old_score = score;

        score = pagerank * old_score;

        column score_diff = score - old_score;

        difference_norm = norm(score_diff, 2);
    }

    return score;
}


column compute_pagerank_2(matrix adjacency_matrix, const double damp, const double error)
{
    int size = adjacency_matrix.size();

    matrix transition_matrix = transition(adjacency_matrix);

    double mean = damp / size;
    double prob = 1.0 / size;
    column score = build(prob, size);

    double difference_norm = norm(score, 2);

    // continue until the score stabilizes
    while (difference_norm > error)
    {
        column old_score = score;

        score = (1 - damp) * (transition_matrix * old_score) + build(mean * norm(old_score, 1), size);

        column score_diff = score - old_score;

        difference_norm = norm(score_diff, 2);
    }

    return score;
}
