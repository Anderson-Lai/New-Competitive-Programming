#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:

    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {

        std::vector<bool> results;
        results.reserve(candies.size());

        auto max = *std::ranges::max_element(candies);
        for (const auto& val : candies) {
            results.push_back(val + extraCandies >= max);
        }
        return results;
    }
};

int main() {

    Solution sol;

    std::vector<int> candies = { 2, 3, 5, 1, 3 };
    for (const auto& val : sol.kidsWithCandies(candies, 3)) {
        std::cout << val << " ";
    };



    return 0;
}