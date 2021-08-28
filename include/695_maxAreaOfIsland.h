//
// Created by lzc on 2021/8/28.
//

#pragma once

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    int dfs(int x, int y, vector<vector<int>> &grid) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
            return 0;
        }
        vector<tuple<int, int>> ds = {{0,  1},
                                      {0,  -1},
                                      {1,  0},
                                      {-1, 0}};
        int sum = 0;
        sum += grid[x][y];
        grid[x][y] = 0;
        for (int i = 0; i < ds.size(); ++i) {
            sum += dfs(x + std::get<0>(ds[i]),
                       y + std::get<1>(ds[i]), grid);
        }
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int ret = dfs(i, j, grid);
                    if (ret > max) {
                        max = ret;
                    }
                }
            }
        }
        return max;
    }

public:

    static void run() {
        vector<vector<int>> in =
                {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                 {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
        auto s = Solution().maxAreaOfIsland(in);
        cout << "ret " << s << endl;

    }

};