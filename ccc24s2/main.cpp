#include <iostream>
#include <cstdint>
#include <format>
#include <ranges>
#include <algorithm>
#include <vector>
#include <unordered_map>

int32_t main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    uint32_t t, n; std::cin >> t >> n;
    for (uint32_t i = 0; i < t; i++) {
        std::string word; std::cin >> word;
        std::unordered_map<char, uint32_t> frequencies;

        for (size_t i = 0; i < n; i++) {
            frequencies[word[i]]++;
        }

        bool light = true;
        for (size_t i = 0; i < n - 1; i++) {
            if ((frequencies.at(word[i]) != 1 && frequencies.at(word[i + 1]) == 1) ||
                (frequencies.at(word[i]) == 1 && frequencies.at(word[i + 1]) != 1)) continue;
            light = false;
        }
        std::cout << (light ? "T" : "F") << "\n";
    }

    return 0;
}