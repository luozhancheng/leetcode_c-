//
// Created by lelezi on 2019-07-30.
//

#ifndef LEETCODE_169_MAJORITY_ELEMENT_H
#define LEETCODE_169_MAJORITY_ELEMENT_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    sort(nums.begin(), nums.end());

    int result = 0;
    int half = nums.size() / 2;
    for (int i = 0; i < half + 1; ++i) {
      if (nums[i] == nums[i + half - 1]) {
        result = nums[i];
      }
    }

    return result;
  }



  static void run() {
    vector<int> v = {3, 2, 3};
    //vector<int> v = {2, 2, 1, 1, 1, 2, 2};
    //vector<int> v = {2, 2};
    cout << Solution().majorityElement(v);
  }
};

#endif //LEETCODE_169_MAJORITY_ELEMENT_H
