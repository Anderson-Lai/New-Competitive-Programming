#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<std::vector<int>> result(2);
        std::unordered_set<int> first, second, firstResult, secondResult;

        for (size_t i = 0; i < nums1.size(); i++) {
            first.insert(nums1[i]);
        }
        for (size_t i = 0; i < nums2.size(); i++) {
            second.insert(nums2[i]);

            if (first.find(nums2[i]) == first.end()) {
                secondResult.insert(nums2[i]);
            }
        }
        for (size_t i = 0; i < nums1.size(); i++) {
            if (second.find(nums1[i]) == second.end()) {
                firstResult.insert(nums1[i]);
            }
        }
        result[0].reserve(firstResult.size());
        result[1].reserve(secondResult.size());

        for (const auto& val : firstResult) {
            result[0].push_back(val);
        }
        for (const auto& val : secondResult) {
            result[1].push_back(val);
        }

        return result;
    }
};

int main() {

    Solution sol;

    std::vector<int> first = { 1,2,3,3 }, second = { 1,1,2,2 };

    auto result = sol.findDifference(first, second);

    for (const auto& val : result[0]) {
        std::cout << val << " ";
    } std::cout << "\n";
    for (const auto& val : result[1]) {
        std::cout << val << " ";
    } std::cout << "\n";

    return 0;
}