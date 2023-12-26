#include "hits.hpp"


std::pair<column, column> compute_hits(matrix adjacency_matrix, const double error, int max_iterations)
{
	int size = adjacency_matrix.size();

	matrix adj_t = transpose(adjacency_matrix);

	column hub = build(1, size);

	column auth = adj_t * hub;

    bool loop = true;
    int iters = 1;

    while (loop)
    {
        if (iters == max_iterations)
            break;

        hub = adjacency_matrix * auth;

        column old_auth = auth;

        auth = adj_t * hub;

        column score_diff = auth - old_auth;
        double difference_norm = norm(score_diff, 2);
        if (difference_norm < error)
            break;

        iters += 1;
    }

    return std::pair<column, column>(auth, hub);
}
