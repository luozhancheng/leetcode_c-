//
// Created by lelezi on 2019-08-02.
//

#ifndef LEETCODE_23_MERGE_K_LIST_H
#define LEETCODE_23_MERGE_K_LIST_H

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    if (lists.empty()) {
      return nullptr;
    }

    ListNode head(0);
    ListNode *h;
    h = &head;

    for (int i = 0; i < lists.size(); ++i) {
      if (lists[i] != nullptr) {
        m.emplace(lists[i]->val, i);
        q.push(lists[i]->val);
      }
    }

    while (!q.empty()) {
      auto it = m.find(q.top());
      int index = it->second;
      q.pop();
      h->next = lists[index];
      lists[index] = lists[index]->next;
      m.erase(it);
      if (lists[index] != nullptr) {
        m.emplace(lists[index]->val, index);
        q.push(lists[index]->val);
      }
      h = h->next;
    }
    return head.next;
  }


  unordered_multimap<int, int> m;
  priority_queue<int, std::vector<int>, std::greater<int>> q;


  static void run()
  {
    vector<ListNode *> v;
    ListNode l1(1);
    ListNode l2(4);
    ListNode l3(5);
    ListNode l4(1);
    ListNode l5(3);
    ListNode l6(4);
    ListNode l7(2);
    ListNode l8(6);
    l1.next = &l2;
    l2.next = &l3;
    l4.next = &l5;
    l5.next = &l6;
    l7.next = &l8;
    v.push_back(&l1);
    v.push_back(&l4);
    v.push_back(&l7);
    auto l = Solution().mergeKLists(v);
    while (l != nullptr) {
      cout << l->val << " ";
      l = l->next;
    }
  }
};

#endif //LEETCODE_23_MERGE_K_LIST_H
