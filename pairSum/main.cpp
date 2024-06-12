#include <iostream>
#include <print>
#include <ranges>
#include <algorithm>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	int pairSum(ListNode* head) {
		std::vector<int> vals;

		while (head != nullptr) {
			vals.push_back(head->val);
			head = head->next;
		}
		int left = 0, right = (vals.size() - 1), max = 0;

		while (left < right) {
			max = std::max(max, vals[left] + vals[right]);
			right--;
			left++;
		}
		return max;
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;

	return 0;
}