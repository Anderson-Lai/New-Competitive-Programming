#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> occurences;
        std::unordered_set<int> seen;

        for (const auto& val : arr) {
            occurences[val]++;
        }

        for (const auto& [k, v] : occurences) {
            if (seen.find(v) != seen.end())
                return false;
            seen.insert(v);
        }
        return true;
    }
};

int main() {

    Solution sol;

    std::vector<int> arr = { -3,0,1,-3,1,1,1,-3,10,0 };

    std::cout << (sol.uniqueOccurrences(arr) ? "True" : "False") << "\n";

    return 0;
}