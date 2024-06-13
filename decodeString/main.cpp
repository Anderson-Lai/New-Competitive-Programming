#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<char> stc;
        std::vector<char> nums = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        std::string str = "", strMultiple = "", temp = "", result = "";
        int multiple = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']')
                stc.push(s[i]);
            else {
                while (stc.top() != '[') {
                    str.push_back(stc.top());
                    stc.pop();
                }
                stc.pop();
                std::ranges::reverse(str);

                // get the factor (k)
                while (!stc.empty() && std::ranges::find(nums, stc.top()) != nums.end()) {
                    strMultiple.push_back(stc.top());
                    stc.pop();
                }
                std::ranges::reverse(strMultiple);
                multiple = std::stoi(strMultiple);

                // "multiplication"
                for (int j = 0; j < multiple; j++) {
                    temp += str;
                }

                for (const auto& c : temp) {
                    stc.push(c);
                }
                str.clear();
                temp.clear();
                strMultiple.clear();
                multiple = 0;
            }
        }
        while (!stc.empty()) {
            result.push_back(stc.top());
            stc.pop();
        }
        std::ranges::reverse(result);
        return result;
    }
};

int main() {

    Solution sol;

    std::cout << sol.decodeString("2[abc]3[cd]ef") << "\n";


    return 0;
}