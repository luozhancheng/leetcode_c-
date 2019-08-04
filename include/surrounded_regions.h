//
// Created by lelezi on 2019-07-14.
//

#ifndef LEETCODE_SURROUNDED_REGIONS_H
#define LEETCODE_SURROUNDED_REGIONS_H


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
        parentB.push_back(0);
        rank.push_back(0);

        if (grid[i][j] == 'O') {
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
    }
  }

  void Setboundary(int x) {
    int root = Find(x);
    parentB[root] = 1;
  }

public:
  vector<int> rank;
  vector<int> parent;
  vector<int> parentB;
};

class Solution {
public:
  void solve(vector<vector<char>> &grid) {
    if (grid.empty() || grid[0].empty())
      return;
    int m = grid.size();
    int n = grid[0].size();
    UnionFinder uf(grid);
    vector<tuple<int, int>> ds = {{0,  1},
                                  {0,  -1},
                                  {1,  0},
                                  {-1, 0}};

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'X') {
          continue;
        }

        for (auto d : ds) {
          int dx = i + std::get<0>(d);
          int dy = j + std::get<1>(d);

          if (dx >= 0 && dy >= 0 && dx < m && dy < n && grid[dx][dy] == 'O') {
            uf.Union(i * n + j, dx * n + dy);
          } else if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
            uf.Setboundary(i * n + j);
          }
        }
      }
    }

    for (auto v : uf.parentB) {
      cout << v << " ";
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'X') {
          continue;
        }
        int root = uf.Find(i * n + j);
        if (uf.parentB[root] == 0) {
          grid[i][j] = 'X';
        }
      }
    }
    cout << endl;
  }


  static void run() {
    vector<vector<char>> grid2 = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    Solution().solve(grid2);

    for (auto i : grid2) {
      for (auto j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
};

#endif //LEETCODE_SURROUNDED_REGIONS_H
