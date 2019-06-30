//
// Created by lelezi on 2019-06-23.
//

#ifndef LEETCODE_QUICK_SORT_H
#define LEETCODE_QUICK_SORT_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums, 0, nums.size() - 1);
    return nums;
  }

  void sort(vector<int>& nums, int b, int e) {
    if (b >= e)
      return;
    int q = partion(nums, b, e);
    sort(nums, b, q - 1);
    sort(nums, q + 1, e);
  }

  int partion(vector<int>& nums, int b, int e) {
    int p = nums[e];
    int i = b;
    for (int j = b; j < e; j++) {
      if (nums[j] < p) {
        if (i != j)
          swap(nums[i], nums[j]);
        i++;
      }
    }
    swap(nums[i], nums[e]);
    return i;
  }

  void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
  }

  static void run() {
    vector<int> v = {5, 2, 3, 1};
    auto r = Solution().sortArray(v);
    for (auto v : r) {
      cout << v << " ";
    }
  }
};

#endif //LEETCODE_QUICK_SORT_H
