//
// Created by lzc on 2021/8/21.
//

#pragma once

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int end = nums.size() - 1;
        int begin = 0;
        while (begin <= end) {
            int index = begin + (end - begin) / 2;
            if (nums[index] == target) {
                return index;
            }
            if (nums[index] > target) {
                end = index - 1;
            } else {
                begin = index + 1;
            }
        }
        return -1;
    }


public:
    static void run() {
        auto s = Solution();
        vector<int> test1 = {-1, 0, 3, 5, 9, 12};
        vector<int> test2 = {-1, 0, 3, 5, 9, 12, 13};
        int ret;
//        ret = s.search(test1, 9);
//        cout << "ret1 = " << ret << endl;
//        ret = s.search(test1, 2);
//        cout << "ret2 = " << ret << endl;
        ret = s.search(test1, 3);
        cout << "ret1 = " << ret << endl;
//        ret = s.search(test1, 5);
//        cout << "ret2 = " << ret << endl;
        ret = s.search(test2, 5);
        cout << "ret1 = " << ret << endl;
    }
};