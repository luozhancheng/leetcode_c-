//
// Created by lzc on 2021/10/12.
//

#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0;
        int t = 0;
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                f++;
                continue;
            } else if (bills[i] == 10) {
                if (f >= 1) {
                    f--;
                    t++;
                } else {
                    return false;
                }
            } else {
                if (t >= 1 && f >= 1) {
                    f--;
                    t--;
                } else if (f >= 3) {
                    f -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

public:
    static void run() {
//        vector<int> b = {5,5,5,10,20};
        vector<int> b = {5,5,10,10,20};
        auto ret = Solution().lemonadeChange(b);
        cout << "ret = " << ret << endl;
    }
};