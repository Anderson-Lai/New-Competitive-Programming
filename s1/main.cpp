#include <iostream>
#include <format>
#include <ranges>
#include <algorithm>
#include <vector>

int32_t main() {
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);

    int32_t n;
    std::cin >> n;

    std::vector<int> hats, left, right;
    hats.reserve(n);

    for (int32_t i = 0; i < n; i++) {
        int32_t h;
        std::cin >> h;
        hats.push_back(h);
    }
    size_t middle = hats.size() / 2;

    left.reserve(hats.size() / 2);
    right.reserve(hats.size() / 2);
    for (size_t i = 0; i < hats.size(); i++) {
        if (i < middle) {
            left.push_back(hats[i]);
        }
        else {
            right.push_back(hats[i]);
        }
    }

    int32_t matching = 0;
    for (size_t i = 0; i < left.size(); i++) {
        if (left[i] == right[i]) matching++;
    }
    std::cout << std::format("{}\n", matching * 2);

    return 0;
}