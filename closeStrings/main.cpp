#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <stack>

class Solution {
public:
    std::string reverseWords(std::string s) {

        std::string temp = "";
        std::stack<std::string> reversed;

        for (const auto& c : s) {
            if (c == ' ') {
                if (temp != "") {
                    reversed.push(temp);
                    temp.clear();
                }
            }
            else {
                temp += c;
            }
        }
        if (temp != "") reversed.push(temp);

        std::string result = "";
        while (!reversed.empty()) {
            auto top = reversed.top();
            reversed.pop();
            result += top;
            result += " ";
        }
        result.pop_back();
        return result;
    }
};

int main() {

    Solution sol;

    std::cout << sol.reverseWords("  hello world  ") << "\n";

    return 0;
}