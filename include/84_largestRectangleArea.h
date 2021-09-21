//
// Created by lzc on 2021/9/21.
//

#pragma once

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> h;
        h.resize(heights.size() + 2);
        h[0] = 0;
        h[h.size() - 1] = 0;
        for (int i = 0; i < heights.size(); ++i) {
            h[i + 1] = heights[i];
        }

        stack<int> s;
        s.push(0);
        int area = 0;

        for (int i = 1; i < h.size(); ++i) {
            while (h[i] < h[s.top()]) {
                int top = s.top();
                s.pop();
                area = max(area, h[top] * (i - 1 - s.top()));
            }
            s.push(i);
        }
        return area;
    }

public:
    static void run() {
        vector<int> h1 = {2,1,5,6,2,3};
        vector<int> h2 = {2, 4};
        vector<int> h3 = {2, 1, 2};
        vector<int> h4 = {2, 1, 1, 2};
        vector<int> h5 = {4, 2, 0, 3, 2 , 5};
        cout << "ret = " << Solution().largestRectangleArea(h1) << endl;
        cout << "ret = " << Solution().largestRectangleArea(h2) << endl;
        cout << "ret = " << Solution().largestRectangleArea(h3) << endl;
        cout << "ret = " << Solution().largestRectangleArea(h4) << endl;
        cout << "ret = " << Solution().largestRectangleArea(h5) << endl;
    }
};