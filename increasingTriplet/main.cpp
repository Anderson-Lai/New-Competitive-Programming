#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:

    bool increasingTriplet(std::vector<int>& nums) {

        int first = INT_MAX;
        int32_t second = INT_MAX;

        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] <= first) {
                first = nums[i];
            }
            else if (nums[i] <= second) {
                second = nums[i];
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main() {

    Solution sol;
    std::vector<int> nums = { 20,100,10,12,5,13 };

    std::cout << sol.increasingTriplet(nums) << "\n";

    return 0;
}