//
// Created by lelezi on 2019-08-18.
//

#ifndef LEETCODE_50_PWERX_N_H
#define LEETCODE_50_PWERX_N_H

#include <iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }

    uint64_t l;
    if (n < 0) {
      x = 1 / x;
      int64_t tmp = static_cast<int64_t>(n);
      l = -tmp;
    } else {
      l = static_cast<uint64_t >(n);
    }

    double res = 1;
    while (l) {
      if (l & 1) {
        res *= x;
      }
      x *= x;
      l = l >> 1;
    }
    return res;
  }


  static void run() {
    cout << Solution().myPow(2, -2);
  }
};

#endif //LEETCODE_50_PWERX_N_H


