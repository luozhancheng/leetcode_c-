//
// Created by lelezi on 2019-08-05.
//

#ifndef LEETCODE_69_SQRT_H
#define LEETCODE_69_SQRT_H

#include <iostream>

using namespace std;

class Solution {
public:
  double mySqrt(int x) {
    if (x <= 1) {
      return x;
    }

    double it = 0;
    double result = 1;
    while (it != result) {
      it = result;
      result = (it + x / it) / 2;
    }

    return static_cast<int>(result);
  }


public:
  static void run() {
    cout << Solution().mySqrt(2);
  }
};


#endif //LEETCODE_69_SQRT_H
