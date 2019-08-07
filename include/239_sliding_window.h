//
// Created by lelezi on 2019-08-04.
//

#ifndef LEETCODE_239_SLIDING_WINDOW_H
#define LEETCODE_239_SLIDING_WINDOW_H

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

ostream &operator<<(ostream &out, vector<int> &v) {
  for (auto val : v) {
    out << val << " ";
  }
  return out;
}


class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> maxValWindow;

    for (int i = 0; i < nums.size(); ++i) {
      if (i >= k && i - maxValWindow.back() >= k) {
        maxValWindow.pop_back();
      }
      while (maxValWindow.size() > 0 && nums[i] > nums[maxValWindow.front()]) {
        maxValWindow.pop_front();
      }
      maxValWindow.push_front(i);
      if (i + 1 >= k) {
        result.push_back(nums[maxValWindow.back()]);
      }
    }

    return result;
  }


public:
  static void run() {
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    auto r = Solution().maxSlidingWindow(v, 3);
    cout << r;
  }

};

#endif //LEETCODE_239_SLIDING_WINDOW_H
