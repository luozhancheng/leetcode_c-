//
// Created by lelezi on 2019-04-26.
//

#ifndef LEETCODE_SQRT_H
#define LEETCODE_SQRT_H


#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
/*  double mySqrt(double x) {
    if (x == 0 || x == 1)
      return x;
    double l = 0, r = x, res = 0;
    double m = 0;
    while (l <= r) {
      m = r - (r - l) / 2;
      cout << "m = " << m << endl;
      if ((m - x / m) < 0.001 && (m - x /m) > -0.001)
        return m;
      else if (m > x / m)
        r = m - 0.001;
      else {
        l = m + 0.001;
        res = m;
      }
    }
    return res;
  }*/
  double mySqrt(double x) {
    if (x == 0 || x == 1)
      return x;
    double l = 0, r = x, res = 0;
    double m = 0;
    while (l <= r) {
      m = r - (r - l) / 2;
      cout << "m = " << m << endl;
      if (m > x / m) {
        r = m - 0.000001;
        res = m;
      }
      else {
        l = m + 0.000001;
        res = m;
      }
    }
    return res;
  }

  static void run() {
    Solution a = Solution();
    auto ret = a.mySqrt(8);
    std::cout << "ret = " << ret << std::endl;
  }
};


#endif //LEETCODE_SQRT_H
