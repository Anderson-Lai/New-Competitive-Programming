#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        size_t n = grid.size();
        std::map<std::vector<int>, int> vertical;

        for (size_t i = 0; i < n; i++) {
            vertical[concat(grid, i, n)]++;
        }

        int result = 0;
        for (size_t i = 0; i < n; i++) {
            if (vertical.find(grid[i]) != vertical.end())
                result += vertical[grid[i]];
        }
        return result;
    }
private:
    std::vector<int> concat(const std::vector<std::vector<int>>& grid, int index, int size) {
        std::vector<int> result;
        for (size_t i = 0; i < size; i++) {
            result.push_back(grid[i][index]);
        }
        return result;
    }
};

int main() {

    Solution sol;

    std::vector<std::vector<int>> grid = {
        {3, 1, 2, 2}, {1, 4, 4, 4}, {2, 4, 2, 2}, {2, 4, 2, 2} };

    std::cout << sol.equalPairs(grid) << "\n";


    return 0;
}