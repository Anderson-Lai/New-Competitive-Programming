#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
    // bool isSubsequence(std::string s, std::string t) {
    //     size_t ssize = s.size();
    //     size_t tsize = t.size();

    //     if (ssize > tsize)
    //         return false;
    //     else if (s == t)
    //         return true;
    //     else if (ssize == 0)
    //         return true;
    //     else if (tsize == 0)
    //         return false;

    //     size_t left = 0, right = 0;

    //     while (left < ssize && right < tsize) {
    //         while (s[left] == t[right]) {
    //             left++;
    //             if (left == ssize)
    //                 return true;
    //             right++;
    //         }
    //         while (right < tsize && t[right] != s[left])
    //             right++;
    //     }
    //     return false;
    // }

    // optimal solution
    bool isSubsequence(std::string s, std::string t) {
        int j = 0;
        for (int i = 0; i < t.size() && j < s.size(); i++) {
            if (t[i] == s[j])
                j++;
        }
        return j == s.size();
    }
};

int32_t main() {

    Solution sol;

    // "", "ahbgdc"
    std::cout << sol.isSubsequence("abc", "ahbgdc");

    return 0;
}