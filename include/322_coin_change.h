//
// Created by lelezi on 2019-08-15.
//

#ifndef LEETCODE_322_COIN_CHANGE_H
#define LEETCODE_322_COIN_CHANGE_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    std::sort(coins.begin(), coins.end(), std::less<int>());
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));

    for (int i = 1; i <= amount; ++i) {
      dp[i][0] = -1;
    }

    for (int i = 1; i <= amount; ++i) {
      int coinIndex = -1;
      int sum = INT_MAX;
      for (int j = 0; j < coins.size(); ++j) {
        if (i >= coins[j] && dp[i - coins[j]][0] != -1) {
          if (dp[i - coins[j]][0] < sum) {
            coinIndex = j;
            sum = dp[i -coins[j]][0];
          }
        }
      }
      if (coinIndex != -1) {
        dp[i] = dp[i - coins[coinIndex]];
        dp[i][0] += 1;
        dp[i][coinIndex + 1] += 1;
      }
    }

    return dp[amount][0];
  }


  static void run() {
    vector<int> c = {186, 419, 83, 408};
    //vector<int> c = {1, 2, 5};
    cout << Solution().coinChange(c, 6249);
  }
};

#endif //LEETCODE_322_COIN_CHANGE_H
