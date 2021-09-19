//
// Created by lzc on 2021/9/18.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& n1 = nums1.size() >= nums2.size() ? nums1 : nums2;
        vector<int>& n2 = nums1.size() < nums2.size() ? nums1 : nums2;
        int m = n1.size();
        int n = n2.size();
        int left = 0;
        int right = m;
        int tl = (m + n + 1) / 2;
        while (left < right) {
            int i = left + (right -left + 1) / 2;
            int j = tl - i;
            int n2Tmp;
            if (j < 0) {
                n2Tmp = INT32_MIN;
            } else if ( j >= n) {
                n2Tmp = INT32_MAX;
            } else {
                n2Tmp = n2[j];
            }
            if (n1[i - 1] > n2Tmp) {
                right = i - 1;
            } else {
                left = i;
            }
        }
        int i = left;
        int j = tl - i;
        int n1lm = i == 0 ? INT32_MIN : n1[i - 1];
        int n1rm = i == m ? INT32_MAX : n1[i];
        int n2lm = j == 0 ? INT32_MIN : n2[j - 1];
        int n2rm = j == n ? INT32_MAX : n2[j];

        if ((m + n) % 2 == 1) {
            return max(n1lm, n2lm);
        } else {
            return (double )((max(n1lm, n2lm) + min(n1rm, n2rm)) / 2.0);
        }
    }
public:
    static void run() {
//                vector<int> n1 = {1,1,1,1,1};
//                vector<int> n2 = {-1, 1,1,1,1,1,2};
//                vector<int> n1 = {1,3};
//                vector<int> n2 = {2};
        vector<int> n1 = {1};
        vector<int> n2 = {2,3,4,5,6};
        cout << "ret = " << Solution().findMedianSortedArrays(n1, n2);
    }

};