//
// Created by lzc on 2021/9/3.
//


#pragma once

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(int cur, int n, int k) {
        if (tmp.size() + n - cur + 1 < k) {
            return;
        }
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k);
        tmp.pop_back();

        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    static void run() {
        auto v = Solution().combine(4, 2);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[0].size(); ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
};