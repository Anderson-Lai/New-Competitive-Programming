#include <iostream>
#include <format>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>

static inline std::unordered_map<char, int32_t> parse
(std::unordered_map<char, int32_t>& first, std::unordered_map<char, int32_t>& second) {
    std::unordered_map<char, int32_t> result;

    for (const auto& [k, v] : first) {
        if (second.find(k) == second.end()) {
            result.insert({ k, v });
        }
    }
    return result;
}
static inline std::unordered_map<char, int32_t> notInFirst
(std::unordered_map<char, int32_t>& first, std::unordered_map<char, int32_t>& second) {
    std::unordered_map<char, int32_t> result;

    for (const auto& [k, v] : second) {
        if (first.find(k) == first.end()) {
            result.insert({ k, v });
        }
    }
    return result;
}

int main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    std::string a, b;
    std::cin >> a >> b;

    std::unordered_map<char, int32_t> first, second;

    // parse strings into a map
    for (const auto& c : a) {
        first[c]++;
    }
    for (const auto& c : b) {
        second[c]++;
    }

    auto parsed = parse(first, second);
    // contains the two keys that are not in the second string
    // the silly and the silent key

    auto inSecond = notInFirst(first, second);
    // finds the keys not in the first string
    // replacement key;

    char silly, silent;
    char replacement = inSecond.begin()->first;
    // silent key is not pressed
    if (parsed.size() == 1) {
        silly = parsed.begin()->first;
        silent = '-';

        std::cout << std::format("{} {}\n{}\n", silly, replacement, silent);
        return 0;
    }

    // differentiate between silly and silent key in parsed
    if (parsed.begin()->second != (++parsed.begin())->second) {
        char toRemove;
        for (const auto& [k, v] : parsed) {
            if (v == inSecond.begin()->second) {
                silly = k;
                toRemove = k;
                break;
            }
        }
        parsed.erase(toRemove);
        silent = parsed.begin()->first;

        std::cout << std::format("{} {}\n{}\n", silly, replacement, silent);
        return 0;
    }
    // edge case if silly and silent key are pressed
    // the same number of times
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == parsed.begin()->first) {
            a[i] = replacement;
        }
        else if (a[i] == (++parsed.begin())->first) {
            a.erase(a.begin() + i);
            i--;
        }
    }
    if (a == b) {
        silly = parsed.begin()->first;
        silent = (++parsed.begin())->first;
    }
    else {
        silly = (++parsed.begin())->first;
        silent = parsed.begin()->first;
    }
    std::cout << std::format("{} {}\n{}\n", silly, replacement, silent);

    return 0;
}