#include <iostream>
#include <vector>

int maximumSubArray(const std::vector<int>& nums) {
    int localMax = nums[0];
    int globalMax = localMax;

    // note:
    // localMax[i - 1] is just the previous localMax

    // the local maximum is nothing more than
    // max(nums[i], localMax[i - 1] + nums[i]) since localMax COULD be negative
    // if localMax[i - 1] is positive, localMax[i - 1] + nums[i] is always > nums[i]

    for (size_t i = 1; i < nums.size(); ++i) {
        localMax = std::max(nums[i], nums[i] + localMax);
        globalMax = std::max(globalMax, localMax);
    }
    return globalMax;
}

int main() {

    std::vector<int> nums = { 1, 2, 4, -6, -5, 10 };

    std::cout << maximumSubArray(nums) << "\n";


    return 0;
}