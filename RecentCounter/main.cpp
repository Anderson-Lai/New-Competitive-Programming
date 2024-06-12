#include <iostream>
#include <print>
#include <ranges>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory>

class RecentCounter {
private:
    std::queue<int> pings;
public:
    RecentCounter() {

    }

    int ping(int t) {
        pings.push(t);

        while (pings.front() < t - 3000) {
            pings.pop();
        }

        if (pings.empty()) {
            return NULL;
        }
        return pings.size();
    }
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

    auto obj = std::make_unique<RecentCounter>();

    int pings[] = { 1, 100, 3001, 3002 };

    for (size_t i = 0; i < sizeof(pings) / sizeof(int); i++) {
        std::cout << obj->ping(pings[i]) << "\n";
    }

	return 0;
}