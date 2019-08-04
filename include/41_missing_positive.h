//
// Created by lelezi on 2019-07-30.
//

#ifndef LEETCODE_41_MISSING_POSITIVE_H
#define LEETCODE_41_MISSING_POSITIVE_H

#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums)
  {
    if (nums.empty()) {
      return 1;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0 || nums[i] >= nums.size() || nums[i] == i + 1) {
        continue;
      }

      if (nums[i] == nums[nums[i] - 1]) {
        continue;
      }

      int tmp = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = tmp;
      --i;
    }

    int i(10);

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }





  static void run()
  {
    vector<int> v = {1, 1};
    cout << Solution().firstMissingPositive(v);
  }
};

#endif //LEETCODE_41_MISSING_POSITIVE_H
