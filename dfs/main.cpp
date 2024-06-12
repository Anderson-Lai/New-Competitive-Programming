#include <iostream>
#include <format>
#include <vector>
#include <unordered_set>

static void dfsHelper(const std::vector<std::vector<int>>& graph, const int& src,
	std::unordered_set<int>& visited) {

	visited.insert(src);

	std::cout << std::format("Visiting: {}\n", src);

	for (int i = 0; i < graph[src].size(); i++) {
		if (graph[src][i] == 1 && visited.find(i) == visited.end())
			dfsHelper(graph, i, visited);
	}
}

static void dfs(const std::vector<std::vector<int>>& graph, const int& src) {
	std::unordered_set<int> visited;
	dfsHelper(graph, src, visited);
}


int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);


	std::vector<std::vector<int>> graph = { {0, 1, 0}, {0, 0, 1}, {1, 0, 0} };

	dfs(graph, 0);


	return 0;
}