//
// Created by lelezi on 2019-05-18.
//

#ifndef LEETCODE_CLIMBING_STAIRS_H
#define LEETCODE_CLIMBING_STAIRS_H


#include <iostream>


class Solution {
public:
  int climbStairs(int n) {
    if (n == 0)
      return 1;
    if (n == 0 || n == 1 || n == 2)
      return n;

    int result = 0;
    int oneStep = 2;
    int twoStep = 1;

    for (int i = 2; i < n ; i++) {
      result = oneStep + twoStep;
      twoStep = oneStep;
      oneStep = result;
    }
    return result;
  }


  static void run() {
    int ret = Solution().climbStairs(3);
    std::cout << "ret = " << ret << std::endl;
  }
};

#endif //LEETCODE_CLIMBING_STAIRS_H
