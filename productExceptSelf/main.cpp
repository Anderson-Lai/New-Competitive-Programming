#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:

    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> results;
        results.reserve(nums.size());

        std::vector<int> pre;
        pre.reserve(nums.size());


        std::vector<int> post;
        post.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) pre.push_back(nums[i]);
            else {
                pre.push_back(pre[i - 1] * nums[i]);
            }
        }

        int j = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) post.push_back(nums[i]);
            else {
                post.push_back(post[j] * nums[i]);
                j++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                results.push_back(1 * (*(post.rbegin() + 1)));
            }
            else if (i == nums.size() - 1) {
                results.push_back(pre[i - 1] * 1);
            }
            else {
                results.push_back(pre[i - 1] * (*(post.rbegin() + i + 1)));
            }
        }

        return results;
    }
};

int main() {

    Solution sol;

    std::vector<int> nums = { -1,1,0,-3,3 };
    for (const auto& val : sol.productExceptSelf(nums)) {
        std::cout << val << " ";
    }

    return 0;
}