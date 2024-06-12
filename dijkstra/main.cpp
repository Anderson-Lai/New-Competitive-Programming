#include <iostream>
#include <queue>
#include <list>
#include <unordered_map>
#include <format>

typedef std::pair<int, int> ipair;

static std::unordered_map<int, int> dijkstra(const std::vector<std::list<ipair>>& graph, const int& src) {
    std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> queue;
    std::unordered_map<int, int> weights;

    size_t n = graph.size();
    for (size_t i = 0; i < n; i++) {
        weights[i] = INT_MAX;
    }

    weights[src] = 0;
    queue.push({ 0, src });

    while (!queue.empty()) {
        int currentWeight = queue.top().first;
        int currentVertex = queue.top().second;
        queue.pop();

        for (const auto& neighbour : graph[currentVertex]) {
            int neighbourVertex = neighbour.first;
            int neighbourWeight = neighbour.second;

            int totalWeight = currentWeight + neighbourWeight;

            if (totalWeight < weights[neighbourVertex]) {
                weights[neighbourVertex] = totalWeight;
                queue.push({ totalWeight, neighbourVertex });
            }
        }
    }
    return weights;
}

int main()
{
    int vertices = 5;
    std::vector<std::list<ipair>> graph(5);

    graph[0].push_back({ 1, 1 });
    graph[0].push_back({ 2, 9 });
    graph[1].push_back({ 2, 3 });
    graph[1].push_back({ 0, 2 });
    graph[1].push_back({ 3, 6 });
    graph[1].push_back({ 4, 19 });
    graph[2].push_back({ 3, 4 });
    graph[2].push_back({ 1, 4 });
    graph[3].push_back({ 2, 7 });
    graph[3].push_back({ 4, 3 });
    graph[4].push_back({ 3,2 });

    auto res = dijkstra(graph, 2);
    for (const auto& [k, v] : res) {
        std::cout << std::format("node: {} \tvalue: {}\n", k, v);
    }

    return 0;
}