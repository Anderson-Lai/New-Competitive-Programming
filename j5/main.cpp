#include <iostream>
#include <vector>

int32_t dfs(std::vector<std::vector<char>>& graph, const int32_t& row, const int32_t& col, const int32_t& r, const int32_t& c) {
    if (row >= r || col >= c
        || row < 0 || col < 0 || graph[row][col] == 'n' || graph[row][col] == '*')
        return 0;

    int32_t curr = 0;
    if (graph[row][col] == 'S') curr = 1;
    else if (graph[row][col] == 'M') curr = 5;
    else if (graph[row][col] == 'L') curr = 10;

    graph[row][col] = 'n';

    return curr + dfs(graph, row - 1, col, r, c) + dfs(graph, row + 1, col, r, c) +
        dfs(graph, row, col - 1, r, c) + dfs(graph, row, col + 1, r, c);
}

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    size_t r, c;
    std::cin >> r >> c;

    std::vector<std::vector<char>> graph(r);

    // create the graph and seed in the data
    for (size_t i = 0; i < r; i++) {
        std::string row;
        std::cin >> row;
        graph[i].reserve(row.size());

        for (size_t j = 0; j < row.size(); j++) {
            graph[i].push_back(row[j]);
        }
    }

    int32_t a, b;
    std::cin >> a >> b;

    std::cout << dfs(graph, a, b, r, c) << "\n";

    return 0;
}