//
// Created by lzc on 2021/10/11.
//

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int sIndex = 0;
        int num = 0;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = sIndex; j < s.size(); ++j) {
                if (s[j] >= g[i]) {
                    num++;
                    sIndex = j + 1;
                    break;
                }
            }
        }
        return num;
    }

public:

    static void run() {
        vector<int> g = {1,2,3};
        vector<int> s = {1,1}   ;
        vector<int> g1 = {1,2};
        vector<int> s1 = {1,2,3}   ;
        auto ret = Solution().findContentChildren(g, s);
        cout << "ret = " << ret << endl;
        auto ret1 = Solution().findContentChildren(g1, s1);
        cout << "ret1 = " << ret1 << endl;
    }

};