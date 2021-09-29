//
// Created by lzc on 2021/9/29.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        int ret = 0;
        vector<int> left(size);
        vector<int> right(size);
        left[0] = 1;
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        right[size - 1] = 1;
        ret += max(right[size - 1], left[size - 1]);
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            } else {
                right[i] = 1;
            }
            ret += max(left[i], right[i]);
        }
        return ret;
    }

public:
    static void run() {
        vector<int> v = {1,0,2};
        vector<int> v1 = {1,2,2};
        cout << Solution().candy(v1) << endl;
        cout << Solution().candy(v) << endl;
    }
};
