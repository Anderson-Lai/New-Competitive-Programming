#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int32_t maxVowels(std::string s, int32_t k) {

        int32_t curr = 0;
        for (int32_t i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                ++curr;
            }
        }
        int32_t max = curr;

        for (int32_t i = k; i < s.length(); i++) {
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' ||
                s[i - k] == 'o' || s[i - k] == 'u')
                --curr;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                ++curr;
            }
            max = std::max(max, curr);
        }
        return max;
    }
};

int32_t main() {

    Solution sol;

    std::cout << sol.maxVowels("leetcode", 3) << "\n";

    return 0;
}