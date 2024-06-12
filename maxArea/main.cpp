#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    int32_t maxArea(std::vector<int32_t>& height) {
        int32_t left = 0, right = (height.size() - 1),
            max = 0;

        while (left < right) {
            max = std::max(max, std::min(height[left], height[right]) * (right - left));

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return max;
    }
};

int32_t main() {

    Solution sol;

    // 1, 1
    // 4,3,2,1,4
    // 2, 1
    // 1,2, 4, 3
    std::vector<int32_t> vec = { 1,3,2,5,25,24,5 };

    std::cout << sol.maxArea(vec) << "\n";

    return 0;
}