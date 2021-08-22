//
// Created by lzc on 2021/8/22.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        for (int i = start; i <= start + (end - start) / 2; ++i) {
            int tmp = nums[i];
            nums[i] = nums[end - i + start];
            nums[end - i + start] = tmp;
        }
    }
    void rotate(vector<int> &nums, int k) {
        if (k == 0 || nums.size() <= 1 || k == nums.size()) {
            return;
        }
        int n = nums.size();
        reverse(nums, 0, n - 1);
        reverse(nums, 0, (k % n) - 1);
        reverse(nums, (k % n), n - 1);
    }

    static void run() {
        auto nums = vector<int>{1, 2};
        int k = 2;

        Solution().rotate(nums, k);
        for (auto &it : nums) {
            std::cout << it << ",";
        }
        std::cout << std::endl;
    }
};
