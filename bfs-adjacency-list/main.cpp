#include <iostream>
#include <cstdint>
#include <format>
#include <ranges>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>

class Graph {
private:
    std::vector<std::list<int32_t>> m_Graph;
    uint32_t m_Vertices;
    std::queue<int32_t> m_Bfs;
    std::unordered_set<int32_t> m_Visited;
public:
    Graph(uint32_t vertices);
    void insertBack(uint32_t row, int32_t val);
    void removeBack(uint32_t row);
    void bfs(uint32_t row);
};

Graph::Graph(uint32_t vertices) : m_Vertices(vertices) {
    m_Graph.resize(vertices);
}
void Graph::insertBack(uint32_t row, int32_t val) {
    m_Graph[row].push_back(val);
}
void Graph::removeBack(uint32_t row) {
    m_Graph[row].pop_back();
}
void Graph::bfs(uint32_t row) {

    m_Bfs.push(row);
    m_Visited.insert(row);

    while (!m_Bfs.empty()) {
        auto front = m_Bfs.front();
        std::cout << std::format("Searching {}\n", front);

        auto curr = m_Graph[front];
        for (const auto& node : curr) {
            if (m_Visited.find(node) == m_Visited.end()) {
                m_Bfs.push(node);
                m_Visited.insert(node);
            }
        }
        m_Bfs.pop();
    }
}

int32_t main() {

    Graph graph(5);
    graph.insertBack(0, 1);
    graph.insertBack(0, 3);
    graph.insertBack(3, 4);
    graph.insertBack(2, 4);
    graph.insertBack(1, 2);

    graph.bfs(0);

    return 0;
}