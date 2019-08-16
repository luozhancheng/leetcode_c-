//
// Created by lelezi on 2019-08-15.
//

#ifndef LEETCODE_64_MIN_PATH_SUM_H
#define LEETCODE_64_MIN_PATH_SUM_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));

    for (int i = 1; i <= grid.size(); ++i) {
      for (int j = 1; j <= grid[0].size(); ++j) {
        if (i == 1) {
          dp[i][j] = grid[i - 1][j - 1] + dp[i][j - 1];
          continue;
        }
        if (j == 1) {
          dp[i][j] = grid[i - 1][j - 1] + dp[i - 1][j];
          continue;
        }
        dp[i][j] = grid[i - 1][j - 1] + std::min(dp[i -1][j], dp[i][j-1]);
      }
    }
    return dp[grid.size()][grid[0].size()];
  }

  static void run() {
    vector<vector<int>> v = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
    };

    cout << Solution().minPathSum(v);
  }
};

#endif //LEETCODE_64_MIN_PATH_SUM_H


