//
// Created by lelezi on 2019-06-23.
//

#ifndef LEETCODE_KTH_ARRAY_H
#define LEETCODE_KTH_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    this->k = k;
    sort(nums, 0, nums.size() - 1);
    return result;
  }

  void sort(vector<int> &nums, int b, int e) {
    if (b >= e) {
      if (b + 1 == k)
        result = nums[k - 1];
      return;
    }
    int q = partion(nums, b, e);
    if (q + 1 == k) {
      result = nums[k - 1];
      return;
    } else if (q + 1 > k)
      sort(nums, b, q - 1);
    else
      sort(nums, q + 1, e);
  }

  int partion(vector<int> &nums, int b, int e) {
    if (b + 1 == k || e + 1 == k) {
      result = nums[k - 1];
    }
    int p = nums[e];
    int i = b;
    for (int j = b; j < e; j++) {
      if (nums[j] > p) {
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

  int result = 0;
  int k = 0;

  static void run() {
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    auto r = Solution().findKthLargest(v, 9);

    cout << "result = " << r << endl;
    for (auto i : v) {
      cout << i << " ";
    }
  }
};

#endif //LEETCODE_KTH_ARRAY_H
