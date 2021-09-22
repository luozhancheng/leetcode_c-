//
// Created by lzc on 2021/9/22.
//

#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maxVal = *max_element(nums.begin(), nums.end());
        int exp = 1;
        vector<int> buf(nums.size());
        while (maxVal >= exp) {
            vector<int> cnt(10);
            for (int i = 0; i < nums.size(); ++i) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; ++i) {
                cnt[i] = cnt[i - 1] + cnt[i];
            }
            for (int i = nums.size() - 1; i >= 0; --i) {
                int digit = (nums[i] / exp) % 10;
                buf[--cnt[digit]] = nums[i];
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int maxDist = 0;
        for (int i = 1; i < nums.size(); ++i) {
            maxDist = max(maxDist, nums[i] - nums[i - 1]);
        }
        return maxDist;
    }

    static void run() {
        vector<int> nums = {3,6,9,1};
        vector<int> nums1 = {10};
        vector<int> nums2 = {1, 10};
        cout << "ret = " << Solution().maximumGap(nums2) << endl;
        cout << "ret = " << Solution().maximumGap(nums) << endl;
        cout << "ret = " << Solution().maximumGap(nums1) << endl;
    }
};
