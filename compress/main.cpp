#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:

    int compress(std::vector<char>& chars) {
        size_t index = 0;
        char character = 0;
        uint32_t occurences = 0;

        for (size_t i = 0; i < chars.size(); i++) {
            if (chars[i] != character && character != 0) {
                chars[index] = character;
                index++;

                if (occurences > 1) {
                    if (occurences >= 10) {
                        std::string temp = std::to_string(occurences);
                        for (const char& c : temp) {
                            chars[index] = c;
                            index++;
                        }
                    }
                    else {
                        chars[index] = std::to_string(occurences)[0];
                        index++;
                    }
                }
                character = 0;
                occurences = 0;
                i--;
            }
            else {
                character = chars[i];
                occurences++;
            }
        }
        chars[index] = character;
        index++;

        if (occurences > 1) {
            if (occurences >= 10) {
                std::string temp = std::to_string(occurences);
                for (const char& c : temp) {
                    chars[index] = c;
                    index++;
                }
            }
            else {
                chars[index] = std::to_string(occurences)[0];
                index++;
            }
        }
        chars.resize(index);
        return chars.size();
    }
};

int32_t main() {

    Solution sol;
    std::vector<char> chars = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };

    auto size = sol.compress(chars);

    for (const auto& val : chars) {
        std::cout << val << " ";
    }

    return 0;
}