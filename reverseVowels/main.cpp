#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stack>

class Solution {
public:

    std::string reverseVowels(std::string s) {
        std::string result = "";

        std::stack<char> reverse;
        std::vector<char> vowels = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };

        for (const auto& c : s) {
            if (std::ranges::find(vowels, c) != vowels.end()) {
                reverse.push(c);
            }
        }
        for (const auto& c : s) {
            if (std::ranges::find(vowels, c) == vowels.end()) {
                result += c;
            }
            else {
                auto top = reverse.top();
                reverse.pop();
                result += top;
            }
        }
        return result;
    }
};

int main() {

    Solution sol;

    std::cout << sol.reverseVowels("leetcode") << "\n";

    return 0;
}