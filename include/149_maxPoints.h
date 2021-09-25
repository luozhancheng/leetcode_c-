//
// Created by lzc on 2021/9/25.
//

#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        int maxPoints = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> m;
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int g = gcd(abs(x), abs(y));
                    x /= g;
                    y /= g;
                }
                m[x + y * 20001] += 1;
                maxPoints = max(maxPoints, m[x + y * 20001] + 1);
            }
        }

        return maxPoints;
    }

public:
    static void run() {
        vector<vector<int>> v = {{1,1},{2,2},{3,3}};
        vector<vector<int>> v1 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
        cout << Solution().maxPoints(v1) << endl;
        cout << Solution().maxPoints(v) << endl;
    }
};
