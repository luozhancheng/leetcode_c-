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
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int l = 1, r = x, res = 0;
        int m = 0;
        while (l <= r) {
            m = r - (r - l) / 2;
            if (m == x / m)
                return m;
            else if (m > x / m)
                r = m - 1;
            else {
                l = m + 1;
                res = m;
            }
        }
        return res;
    }

    static void run() {
        Solution a = Solution();
        int ret = a.mySqrt(8);
        std::cout << "ret = " << ret << std::endl;
    }
};


#endif //LEETCODE_SQRT_H
