#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        int left = 0;
        int right = 0;

        for (const auto& val : nums)
            sum += val;

        // is slower due to the function call, is more concise though
        // int sum = std::accumulate(nums.begin(), nums.end(), 0);

        // base case for nums[0]
        if (sum - nums[0] == 0)
            return 0;

        for (size_t i = 1; i < nums.size(); i++) {
            left += nums[i - 1];
            right = sum - left - nums[i];

            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    Solution sol;
    std::vector<int> nums = { 1 };

    std::cout << sol.pivotIndex(nums) << "\n";


    return 0;
}