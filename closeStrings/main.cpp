#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

// class Solution {
// public:
//     bool closeStrings(std::string word1, std::string word2) {
//         if (word1.size() != word2.size())
//             return false;

//         std::unordered_map<char, int> m1, m2;
//         std::set<char> s1, s2;
//         std::vector<int> v1, v2;

//         for (size_t i = 0; i < word1.size(); i++) {
//             m1[word1[i]]++;
//             m2[word2[i]]++;
//             s1.insert(word1[i]);
//             s2.insert(word2[i]);
//         }

//         v1.reserve(m1.size());
//         v2.reserve(m2.size());
//         for (const auto& [k, v] : m1) {
//             v1.push_back(v);
//         }
//         for (const auto& [k, v] : m2) {
//             v2.push_back(v);
//         }
//         std::ranges::sort(v1);
//         std::ranges::sort(v2);

//         return v1 == v2 && s1 == s2;
//     }

//     bool closeStrings(std::string word1, std::string word2) {
//         if (word1.size() != word2.size())
//             return false;

//         std::vector<int> freq1(26, 0), freq2(26, 0);
//         std::set<char> s1, s2;

//         for (size_t i = 0; i < word1.size(); i++) {
//             char first = word1[i], second = word2[i];
//             freq1[first - 'a']++;
//             freq2[second - 'a']++;

//             s1.insert(first);
//             s2.insert(second);
//         }
//         std::ranges::sort(freq1);
//         std::ranges::sort(freq2);

//         return freq1 == freq2 && s1 == s2;
//     }
// };

class Solution
{
public:
    bool closeStrings(std::string word1, std::string word2)
    {
        if (word1.size() != word2.size())
            return false;

        std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for (size_t i = 0; i < word1.size(); i++) {
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            // check if letter exists (value != 0) in one vector but not the other (value == 0)
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0))
            {
                return false;
            }
        }

        std::ranges::sort(freq1);
        std::ranges::sort(freq2);

        return freq1 == freq2;
    }
};

int main() {

    Solution sol;

    std::cout << (sol.closeStrings("abbzccca", "babzzczc") ? "True" : "False") << "\n";

    return 0;
}