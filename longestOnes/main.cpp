#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    int32_t longestOnes(std::vector<int>& nums, int32_t k) {
        int left = 0, right = 0;
        int max = 0, zeroes = 0;

        for (right = 0; right < nums.size(); right++) {
            if (nums[right] == 1)
                max = std::max(max, right - left + 1);
            else {
                zeroes++;
                while (zeroes > k) {
                    if (nums[left] == 0) {
                        left++;
                        zeroes--;
                    }
                    else {
                        left++;
                    }
                }
                max = std::max(max, right - left + 1);
            }
        }
        return max;
    }
};

int32_t main() {

    Solution sol;

    std::vector<int> binary = { 1,1,1,0,0,0,1,1,1,1,0 };
    std::cout << sol.longestOnes(binary, 2) << "\n";

    return 0;
}