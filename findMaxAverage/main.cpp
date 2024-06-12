#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    double findMaxAverage(std::vector<int32_t>& nums, int32_t k) {

        int32_t sum = 0;
        for (size_t i = 0; i < k; i++) {
            sum += nums[i];
        }

        int32_t max = sum;

        for (size_t i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            max = std::max(max, sum);
        }
        return (double)max / (double)k;
    }
};

int32_t main() {

    Solution sol;

    // 0, 1, 1, 3, 3
    std::vector<int> nums = { 0, 1, 1, 3, 3 };

    std::cout << sol.findMaxAverage(nums, 4) << "\n";


    return 0;
}