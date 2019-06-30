//
// Created by lelezi on 2019-06-02.
//

#ifndef LEETCODE_SUB_SEQ_H
#define LEETCODE_SUB_SEQ_H


#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
  ~Solution() {
    if (dp != nullptr)
      delete []dp;
  }
  int lengthOfLIS2(vector<int>& nums) {
    if (nums.empty())
      return 0;

    int ret = 1;
    dp = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++)
      dp[i] = 1;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i])
          dp[i] = std::max(dp[i], dp[j] + 1);
      }
      ret = std::max(ret, dp[i]);
    }

    return ret;
  }

  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty())
      return 0;

    vector<int> ret;

    for (int i = 0; i < nums.size(); i++) {
      auto it = std::lower_bound(ret.begin(), ret.end(), nums[i]);
      if (it == ret.end())
        ret.push_back(nums[i]);
      else
        *it = nums[i];
    }

    return ret.size();
  }

  int *dp = {nullptr};

  static void run() {
    vector<int> input = {10,9,2,5,3,7,101,18};
    auto ret = Solution().lengthOfLIS(input);
    cout << "len = " << ret << endl;
  }
};

#endif //LEETCODE_SUB_SEQ_H
