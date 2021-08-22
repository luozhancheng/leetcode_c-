//
// Created by lzc on 2021/8/22.
//

#pragma once

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int index = left + (right - left) / 2;;
            if (isBadVersion(index)) {
                right = index - 1;
                n = index;
            } else {
                left = index + 1;
            }
        }
        return n;
    }
public:
    bool isBadVersion(int n) {
        auto r = (n >= b ? true : false);
        std::cout << n << " is bad version ? " << r << std::endl;
        return r;
    }

    static void run() {
        std::cout << "first bad version is " << Solution().firstBadVersion(9) << std::endl;
    }

    int b = 4;
};