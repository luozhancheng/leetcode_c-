//
// Created by lzc on 2021/8/31.
//


#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        if (mat.size() == 0 || mat[0].size() == 0) {
            return vector<vector<int>>{};
        }
        int rol = mat.size();
        int col = mat[0].size();
        vector<vector<int>> res;
        res.resize(rol);
        for (int i = 0; i < rol; ++i) {
            res[i].resize(col);
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < rol; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                } else {
                    res[i][j] = INT32_MAX;
                }
            }
        }

        vector<pair<int, int>> ds = {{0,  1},
                                     {0,  -1},
                                     {1,  0},
                                     {-1, 0}};
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            for (int i = 0; i < ds.size(); ++i) {
                if (n.first + ds[i].first < 0 || n.first + ds[i].first >= rol ||
                    n.second + ds[i].second < 0 || n.second + ds[i].second >= col) {
                    continue;
                }
                if (res[n.first + ds[i].first][n.second + ds[i].second] > res[n.first][n.second] + 1) {
                    res[n.first + ds[i].first][n.second + ds[i].second] = res[n.first][n.second] + 1;
                    q.push({n.first + ds[i].first, n.second + ds[i].second});
                }
            }
        }

        return res;
    }

public:

    static void run() {
        vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
        auto s = Solution().updateMatrix(mat);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s[0].size(); ++j) {
               cout << s[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

};