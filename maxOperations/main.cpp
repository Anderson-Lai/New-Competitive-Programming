#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
    // int32_t maxOperations(std::vector<int>& nums, int32_t k) {
    //     std::unordered_map<int32_t, int32_t> map;
    //     for (const auto& val : nums) {
    //         map[val]++;
    //     }

    //     int32_t operations = 0; 
    //     for (const auto& val : nums) {
    //         int32_t target = k - val;
    //         if (map.find(target) != map.end()) {
    //             map[target]--;
    //             if (map[target] == 0)
    //                 map.erase(target);
    //             if (map.find(val) != map.end()) {
    //                 map[val] --;
    //                 if (map[val] == 0) 
    //                     map.erase(val);
    //                 operations++;
    //             }  
    //         } 
    //     }
    //     return operations;
    // }
    int32_t maxOperations(std::vector<int>& nums, int32_t k) {
        std::ranges::sort(nums);

        int32_t operations = 0, left = 0,
            right = (nums.size() - 1);

        while (left < right) {
            if (nums[left] + nums[right] == k) {
                ++left;
                --right;
                ++operations;
            }
            else if (nums[left] + nums[right] > k)
                --right;
            else if (nums[left] + nums[right] < k)
                ++left;
        }
        return operations;
    }
};

int32_t main() {

    Solution sol;

    std::vector<int> nums = { 1,2,3,4 };
    std::cout << sol.maxOperations(nums, 5) << "\n";

    return 0;
}