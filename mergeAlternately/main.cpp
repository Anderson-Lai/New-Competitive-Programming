#include <iostream>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result = "";
        size_t left = 0;
        size_t right = 0;

        while (left < word1.size() && right < word2.size()) {
            result += word1[left];
            result += word2[right];
            left++;
            right++;
        }
        if (left >= word1.size()) {
            for (size_t i = right; i < word2.size(); i++) {
                result += word2[i];
            }
        }
        else {
            for (size_t i = left; i < word1.size(); i++) {
                result += word1[i];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::cout << sol.mergeAlternately("ab", "pqrs") << std::endl;

    return 0;
}