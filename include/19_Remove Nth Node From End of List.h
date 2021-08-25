//
// Created by lzc on 2021/8/25.
//

#pragma once

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            return slow->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }

    static void run() {
        auto a = new ListNode(5);
        auto b = new ListNode(4, a);
        auto c = new ListNode(3, b);
        auto d = new ListNode(2, c);
        auto e = new ListNode(1, d);
        ListNode* r = Solution().removeNthFromEnd(e, 2);
        while (r != nullptr) {
            std::cout << r->val << " ";
            r = r->next;
        }
        std::cout << std::endl;
    }

};
