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
	ListNode* reverseList(ListNode* head) {
		// check for nullptr for all linked list questions
		if (head == nullptr)
			return nullptr;
		else if (head->next == nullptr)
			return head;

		ListNode* previous = head;

		// check for a linked list of length 2
		head = head->next;
		if (head->next == nullptr) {
			previous->next = nullptr;
			head->next = previous;
			return head;
		}

		previous->next = nullptr;
		ListNode* nextNode = head->next;
		//ListNode* result = previous;

		ListNode* temp = nullptr;
		while (nextNode != nullptr) {
			// reverse
			head->next = previous;
			// bring previous up to head
			previous = head;
			// move head to the next node
			head = nextNode;
			// store the next next node
			temp = nextNode->next;
			// mend the head to point to prev
			head->next = previous;
			// move to next next node
			nextNode = temp;
		}
		return head;
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;

	ListNode e(5);
	ListNode d(4, &e);
	ListNode c(3, &d);
	ListNode b(2, &c);
	ListNode a(1, &b);

	auto res = sol.reverseList(&a);

	while (res != nullptr) {
		std::cout << res->val << "\n";
		res = res->next;
	}

	return 0;
}