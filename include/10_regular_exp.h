//
// Created by lelezi on 2019-08-13.
//

#ifndef LEETCODE_10_REGULAR_EXP_H
#define LEETCODE_10_REGULAR_EXP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    dp[0][0] = true;

    // *前必须有一个字符
    for (int i = 1; i < p.size(); ++i) {
      if (p[M(i)] == '*') {
        dp[0][i] = dp[0][i - 2] || dp[0][i - 1];
      }
    }

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          if (s[i - 1] != p[j - 2]) {
            dp[i][j] = dp[i][j - 2];
            }

          if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
            dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
          }
        }
      }
    }

    return dp[s.size()][p.size()];
  }


  inline int M(int val) {
    return val - 1;
  }

  static void run() {
    cout << Solution().isMatch("aab", "c*a*b");
  }
};


/*
p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]
If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
If p.charAt(j) == '*': here are two sub conditions:
//in this case, a* only counts as empty, otherwise is not match
- if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]
- if p.charAt(j-1) == s.charAt(i) or p.charAt(i-1) == '.':
dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
 */

#endif //LEETCODE_10_REGULAR_EXP_H
