#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int32_t i = 0;
        int32_t j = 1;

        while (j < nums.size()) {
            if (nums[i] == 0 && nums[j] != 0) {
                std::swap(nums[j], nums[i]);
                i++;
                j++;
            }
            else if (nums[i] == 0 && nums[j] == 0) {
                while (j < nums.size() && nums[j] == 0)
                    j++;
            }
            else {
                i++;
                j++;
            }
        }
    }
};

int32_t main() {

    Solution sol;

    // 0, 0, 1
    // 0, 0
    // 1, 0
    // 1, 0, 1
    std::vector<int> nums = { 1, 0, 1 };
    sol.moveZeroes(nums);

    for (const auto& val : nums)
        std::cout << val << " ";

    return 0;
}