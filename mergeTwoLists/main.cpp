#include <iostream>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <vector>
#include <memory>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }
        else if (!list1) {
            return list2;
        }
        else if (!list2) {
            return list1;
        }

        ListNode dummy;
        ListNode* head = &dummy;
        if (list1->val <= list2->val) {
            head->next = list1;
            list1 = list1->next;
        }
        else {
            head->next = list2;
            list2 = list2->next;
        }
        ListNode* result = head;
        head = head->next;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            }
            else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list1 || list2) {
            if (!list1 && list2) {
                head->next = list2;
            }
            else if (list1 && !list2) {
                head->next = list1;
            }
        }
        return result->next;
    }
};

int32_t main() {

    Solution sol;

    ListNode* c = new ListNode(4);
    ListNode* b = new ListNode(2, c);
    ListNode* first = new ListNode(1, b);


    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(3, d);
    ListNode* second = new ListNode(1, e);

    auto returned = sol.mergeTwoLists(first, second);

    while (returned != nullptr) {
        std::cout << returned->val << "\n";
        returned = returned->next;
    }


    return 0;
}