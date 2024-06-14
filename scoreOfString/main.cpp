#include <iostream>
#include <print>
#include <ranges>
#include <algorithm>
#include <vector>

class Solution {
public:
	int scoreOfString(std::string s) {
		int total = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			int curr = std::abs(s[i] - s[i + 1]);
			total += curr;
		}
		return total;
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;



	return 0;
}