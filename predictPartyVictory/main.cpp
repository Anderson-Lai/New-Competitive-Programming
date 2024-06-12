#include <iostream>
#include <print>
#include <ranges>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

class Solution {
public:
	std::string predictPartyVictory(std::string senate) {
		std::queue<char> council, temp;

		for (const auto& member : senate) {
			council.push(member);
		}

		temp.push(council.front());
		council.pop();

		while (council.front() == temp.front()) {
			temp.push(council.front());
			council.pop();
		}
		while (!council.empty()) {
			if (council.front() != temp.front()) {
				council.pop();
				council.push(temp.front());
				temp.pop();

				if (temp.empty()) {
					temp.push(council.front());
					council.pop();
				}
			}
			else {
				temp.push(council.front());
				council.pop();
			}
		}
		return temp.front() == 'R' ? "Radiant" : "Dire";
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;

	std::cout << sol.predictPartyVictory("RDD") << "\n";

	return 0;
}