#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <deque>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::deque<char> letters;
        std::string result = "";

        for (const auto& c : s) {
            if (!letters.empty() && c == '*')
                letters.pop_back();
            else if (c != '*')
                letters.push_back(c);
            else
                return "";
        }
        while (!letters.empty()) {
            result += letters.front();
            letters.pop_front();
        }
        return result;
    }
};

int main() {

    Solution sol;

    std::cout << sol.removeStars("e") << "\n";

    return 0;
}