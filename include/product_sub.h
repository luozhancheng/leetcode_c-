//
// Created by lelezi on 2019-05-19.
//

#ifndef LEETCODE_PRODUCT_SUB_H
#define LEETCODE_PRODUCT_SUB_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    int dp[2][2] = {0};
    int res = dp[0][0] = dp[0][1] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      int x = i % 2;
      int y = (i - 1) % 2;

      dp[x][0] = max(max(dp[y][0] * nums[i], dp[y][1] * nums[i]), nums[i]);
      dp[x][1] = min(min(dp[y][0] * nums[i], dp[y][1] * nums[i]), nums[i]);
      res = max(res,dp[x][0]);
    }

    return res;
  }


  static void run() {
    vector<int> l = {2,3,-2,4};
    int ret = Solution().maxProduct(l);
    std::cout << "ret = " << ret << std::endl;
  }
};

#endif //LEETCODE_PRODUCT_SUB_H
