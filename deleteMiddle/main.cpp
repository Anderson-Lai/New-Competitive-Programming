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

	ListNode* deleteMiddle(ListNode* head) {
		int length = 0, index = 0;
		ListNode* cpy = head;

		while (head != nullptr) {
			length++;
			head = head->next;
		}

		if (length == 0 || length == 1)
			return nullptr;

		head = cpy;
		int middle = length / 2;
		ListNode* previous = nullptr;

		while (index != middle) {
			previous = head;
			head = head->next;
			index++;
		}
		previous->next = head->next;
		return cpy;
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;

	ListNode g(6);
	ListNode f(2, &g);
	ListNode e(1, &f);
	ListNode d(7, &e);	
	ListNode c(4, &d);
	ListNode b(3, &c);
	ListNode a(1, &b);

	auto res = sol.deleteMiddle(&a);

	while (res != nullptr) {
		std::cout << res->val << "\n";
		res = res->next;
	}

	return 0;
}