#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

class Solution {
public:

    std::string gcdOfStrings(std::string str1, std::string str2) {
        if (str1 == str2) {
            return str1;
        }
        else if (str1.size() > str2.size()) return gcdOfStrings(str2, str1);

        size_t left = str1.size();
        size_t right = str2.size();
        std::string result = "";

        for (size_t i = 1; i <= left; i++) {
            if (left % i == 0 && right % i == 0) {
                size_t leftMultiple = left / i;
                size_t rightMultiple = right / i;

                std::string temp = str1.substr(0, i);
                std::string str1cpy = temp;

                for (size_t j = 0; j < leftMultiple - 1; j++) {
                    str1cpy += temp;
                }
                std::string str2cpy = str1cpy;
                for (size_t j = leftMultiple; j < rightMultiple; j++) {
                    str2cpy += temp;
                }

                if (str1cpy == str1 && str2cpy == str2) {
                    result = temp;
                }
            }
        }
        return result;
    }
};

int main() {

    Solution sol;

    std::cout << sol.gcdOfStrings("ABCABC", "ABC") << std::endl;


    return 0;
}