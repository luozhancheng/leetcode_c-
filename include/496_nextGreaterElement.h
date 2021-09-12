//
// Created by lzc on 2021/9/12.
//

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i) {
            if (s.empty()) {
                s.push(nums2[i]);
                continue;
            }
            while (!s.empty() && nums2[i] > s.top()) {
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            result.push_back(m[nums1[i]]);
        }
        return result;
    }
public:

    static void run() {
        vector<int> n1 = {2, 4};
        vector<int> n2 = {1,2,3,4};
        vector<int> n3 = {4,1, 2};
        vector<int> n4 = {1,3,4,2};
//        auto s = Solution().nextGreaterElement(n1, n2);
        auto s = Solution().nextGreaterElement(n3, n4);
        for (const auto it : s) {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

};