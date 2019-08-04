//
// Created by lelezi on 2019-07-23.
//

#ifndef LEETCODE_44WILDCARD_MATCHING_H
#define LEETCODE_44WILDCARD_MATCHING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    int len1 = s.size();
    int len2 = p.size();


    for (int i = 0; i <= len1; i++) {
      vector<bool> tmp;
      for (int j = 0; j <= len2; j++) {
        tmp.push_back(false);
      }
      dp.push_back(tmp);
    }
    dp[0][0] = true;
    for (int j = 1; j <= len2; j++) {
      if (p[j - 1] == '*') {
        dp[0][j] = dp[0][j - 1];
      }
    }

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        char ch1 = s[i - 1];
        char ch2 = p[j - 1];
        if (ch1 == ch2 || ch2 == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        }
        if (ch2 == '*') {
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
          printf("dp[%d][%d] = %d\n", i, j - 1, (int)dp[i][j - 1]);
          printf("dp[%d][%d] = %d\n", i - 1, j, (int)dp[i-1][j]);
          printf("dp[%d][%d] = %d\n", i, j, (int)dp[i][j]);
          cout << endl;
        }
      }
    }
    return dp[len1][len2];
  }



  vector<vector<bool>> dp;

  static void run() {
    int ret = Solution().isMatch("aa", "*");
    cout << ret << endl;
  }
};


/*
如果p[j] == s[i]或p[j] == '?'，即子串的最后一个字符匹配，所以问题转化为去除最后字符的新子串的匹配问题：dp[i][j] = dp[i - 1][j - 1]。
如果p[j] == '*'，则有两种情况：
*匹配了字符，匹配多少个呢？我们这里可以不关注，就让它匹配1个字符，且p本身不变，再去匹配s子串去除第一个字符的新子串：dp[i][j] = dp[i - 1][j]；
*不匹配字符，则s不变，用p子串去除第一个字符的子串去匹配：dp[i][j] = dp[i][j - 1]。
*/



#endif //LEETCODE_44WILDCARD_MATCHING_H
