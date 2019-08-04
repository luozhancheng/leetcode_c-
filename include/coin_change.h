//
// Created by lelezi on 2019-07-24.
//

#ifndef LEETCODE_COIN_CHANGE_H
#define LEETCODE_COIN_CHANGE_H

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int change(int amount, vector<int>& coins) {

    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    for (auto c : coins) {
      for (int i = 1; i <= amount; i++) {
        if (i >= c) {
          dp[i] = dp[i] + dp[i - c];
        }
      }
    }

    return dp[amount];


  }



  static void run() {
    vector<int> v = {1, 2, 5};
    cout << Solution().change(5, v);
  }
};



#endif //LEETCODE_COIN_CHANGE_H
