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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* evenHead = nullptr, * oddHead = nullptr, * result = head, * evenStart = nullptr;

		if (head == nullptr)
			return nullptr;

		int index = 1;
		while (head != nullptr) {
			if (even(index)) {
				if (evenHead == nullptr) {
					evenHead = head;
					evenStart = evenHead;
				}
				else {
					evenHead->next = head;
					evenHead = evenHead->next;
				}
			}
			else {
				if (oddHead == nullptr) {
					oddHead = head;
				}
				else {
					oddHead->next = head;
					oddHead = oddHead->next;
				}
			}

			head = head->next;
			index++;
		}
		if (evenHead == nullptr)
			return result;
		evenHead->next = nullptr;
		oddHead->next = evenStart;

		return result;
	}
private:
	static inline bool even(const int& index) {
		return index % 2 == 0;
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

	auto res = sol.oddEvenList(&a);

	while (res != nullptr) {
		std::cout << res->val << "\n";
		res = res->next;
	}

	return 0;
}