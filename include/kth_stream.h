//
// Created by lelezi on 2019-06-23.
//

#ifndef LEETCODE_KTH_STREAM_H
#define LEETCODE_KTH_STREAM_H

#include <iostream>
#include <queue>
#include <functional>

using namespace std;


class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) : index(k) {
    for (auto val : nums) {
      add(val);
    }
  }

  int add(int val) {
    if (pq.size() < index) {
      pq.push(val);
    } else {
      if (val > pq.top()) {
        pq.pop();
        pq.push(val);
      }
    }
    return pq.top();
  }

private:
  int index = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
};

class Solution {
public:
  static void run() {
    vector<int> a = {4, 5, 8, 2};
    KthLargest k(3, a);
    cout << "k th = " << k.add(3) << endl;
    cout << "k th = " << k.add(5) << endl;
  }
};


#endif //LEETCODE_KTH_STREAM_H
