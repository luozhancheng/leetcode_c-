//
// Created by lelezi on 2019-08-11.
//

#ifndef LEETCODE_51_N_Q_I_H
#define LEETCODE_51_N_Q_I_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    if (n <= 0) {
      return {{}};
    }

    vector<int> v;
    DFS(n, 0, 0, 0, 0, v);
    return result;
  }

  void DFS(int n, int row, int col, int pil, int na, vector<int> &v) {
    if (row >= n) {
      vector<string> res(n, string(n, '.'));
      for (int i = 0; i < n; ++i) {
        res[i][static_cast<int>(log2(v[i]))] = 'Q';
      }
      result.push_back(res);
      return;
    }

    int bits = (~(col | pil | na)) & ((1 << n) - 1);

    while(bits) {
      int bit = bits & (-bits);
      v.push_back(bit);
      DFS(n, row + 1, col | bit, (pil | bit) << 1, (na | bit) >> 1, v);
      bits = bits & (bits - 1);
      v.pop_back();
    }
  }

  vector<vector<string>> result;

  static void run() {
    auto r = Solution().solveNQueens(4);
    for (auto v : r) {
      for (auto c : v) {
        cout << c << endl;
      }
      cout << endl << endl;
    }
  }
};

#endif //LEETCODE_51_N_Q_I_H
