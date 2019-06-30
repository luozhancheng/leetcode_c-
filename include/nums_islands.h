//
// Created by lelezi on 2019-06-08.
//

#ifndef LEETCODE_NUMS_ISLANDS_H
#define LEETCODE_NUMS_ISLANDS_H

#include <vector>
#include <iostream>

using namespace std;

class UnionFinder {
public:
  UnionFinder(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        parent.push_back(-1);
        rank.push_back(0);

        if (grid[i][j] == '1') {
          count++;
          parent[i * n + j] = i * n + j;
        }
      }
    }
  }

  int Find(int i) {
    if (parent[i] != i) {
      parent[i] = Find(parent[i]);
    }
    return parent[i];
  }

  void Union(int x, int y) {
    int rootx = Find(x);
    int rooty = Find(y);

    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
      } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
      } else {
        parent[rooty] = rootx;
        rank[rootx] += 1;
      }
      count--;
    }
  }

public:
  int count = 0;
  vector<int> rank;
  vector<int> parent;
};

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty())
      return 0;
    int m = grid.size();
    int n = grid[0].size();
    UnionFinder uf(grid);
    vector<tuple<int, int>> ds = {{0,  1},
                                  {0,  -1},
                                  {1,  0},
                                  {-1, 0}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '0') {
          continue;
        }

        for (auto d : ds) {
          int dx = i + std::get<0>(d);
          int dy = j + std::get<1>(d);

          if (dx >= 0 && dy >= 0 && dx < m && dy < n && grid[dx][dy] == '1') {
            uf.Union(i * n + j, dx * n + dy);
          }
        }
      }
    }
    return uf.count;
  }


  static void run() {
    vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '1', '0', '0'},
                                  {'0', '0', '0', '1', '1'}};
    vector<vector<char>> grid1 = {{'1', '1', '1', '1', '0'},
                                  {'1', '1', '0', '1', '0'},
                                  {'1', '1', '0', '0', '0'},
                                  {'0', '0', '0', '0', '0'}};
    int ret1 = Solution().numIslands(grid1);
    int ret2 = Solution().numIslands(grid2);

    std::cout << "ret1 = " << ret1 << endl;
    std::cout << "ret2 = " << ret2 << endl;
  }
};

#endif //LEETCODE_NUMS_ISLANDS_H
