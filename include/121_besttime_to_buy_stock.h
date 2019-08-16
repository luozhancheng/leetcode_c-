//
// Created by lelezi on 2019-08-16.
//

#ifndef LEETCODE_121_BESTTIME_TO_BUY_STOCK_H
#define LEETCODE_121_BESTTIME_TO_BUY_STOCK_H

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

    dp[0][0] = -1;
    dp[0][1] = INT_MAX;

    for (int i = 1; i <= prices.size(); ++i) {
      if (prices[i - 1] < dp[i - 1][1]) {
        dp[i][1] = prices[i - 1];
        dp[i][0] = dp[i - 1][0];
      } else {
        dp[i][0] = std::max(dp[i - 1][0], prices[i - 1] - dp[i - 1][1]);
        dp[i][1] = dp[i - 1][1];
      }
    }

    return dp[prices.size()][0] == -1 ? 0 :  dp[prices.size()][0];
  }

  static void run() {
    vector<int> v = {7,1,5,3,6,4};
    cout << Solution().maxProfit(v);
  }
};
#endif //LEETCODE_121_BESTTIME_TO_BUY_STOCK_H
