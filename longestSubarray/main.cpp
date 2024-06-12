#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        // base cases
        if (nums.size() == 1) {
            return 0;
        }

        int zeroes = 0, ones = 0;
        for (const auto& val : nums) {
            if (val == 0)
                zeroes++;
            else if (val == 1)
                ones++;
        }
        if (zeroes == nums.size())
            return 0;
        else if (ones == nums.size())
            return nums.size() - 1;
        else if (zeroes == 1)
            return nums.size() - 1;

        // main loop
        int left = 0, right = 0, max = 0;
        bool zero = false;
        for (; right < nums.size(); right++) {
            if (nums[right] == 0 && !zero) {
                zero = true;
            }
            else if (nums[right] == 0 && zero) {
                max = std::max(max, right - left - 1);
                if (nums[left] == 0) {
                    // bring left to the nearest "1"
                    while (nums[left] == 0 && left < right)
                        left++;
                }
                else {
                    // bring left to the "1" after the "0"
                    while (nums[left] == 1 && left < right)
                        left++;
                    left++;
                }
            }
            if (zero) {
                // decrement one as there is a "0" in the size calculation
                max = std::max(max, right - left);
            }
            else {
                max = std::max(max, right - left + 1);
            }

        }
        return max;
    }
};

int main() {

    Solution sol;
    std::vector<int> nums = { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 };

    std::cout << sol.longestSubarray(nums) << "\n";

    for (const auto& val : nums) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}