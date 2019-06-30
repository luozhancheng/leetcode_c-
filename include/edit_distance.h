//
// Created by lelezi on 2019-06-06.
//

#ifndef LEETCODE_EDIT_DISTANCE_H
#define LEETCODE_EDIT_DISTANCE_H


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int **dp;

    dp = new int *[len1 + 1];
    for (int i = 0; i < len1 + 1; i++) {
      dp[i] = new int[len2 + 1];
      for (int j = 0; j < len2 + 1; j++) {
        dp[i][j] = 0;
      }
    }

    for (int i = 0; i < len1 + 1; i++) {
      dp[i][0] = i;
    }

    for (int j = 0; j < len2 + 1; j++) {
      dp[0][j] = j;
    }


    for (int i = 1; i < len1 + 1; i++) {
      for (int j = 1; j < len2 + 1; j++) {
        dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                       word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
      }
    }

    int ret = dp[len1][len2];

    for (int i = 0; i < len1 + 1; i++) {
      delete[] dp[i];
    }
    delete[] dp;

    return ret;
  }


  static void run() {
    string word1 = "horse";
    string word2 = "ros";
    int ret = Solution().minDistance(word1, word2);
    std::cout << "ret = " << ret << endl;
  }
};

#endif //LEETCODE_EDIT_DISTANCE_H
