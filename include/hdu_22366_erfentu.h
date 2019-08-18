//
// Created by lelezi on 2019-08-18.
//

#ifndef LEETCODE_HDU_22366_ERFENTU_H
#define LEETCODE_HDU_22366_ERFENTU_H


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
  Solution(const vector<vector<int>> &matrix) : matrix(matrix) {
    size = matrix.size();
    for (auto vec : matrix) {
      for (auto val : vec) {
        if (val > mmax) {
          mmax = val;
        }
        if (val < mmin) {
          mmin = val;
        }
      }
    }
  }

  ~Solution() {}

  bool DFS(int row) {
    for (int i = 0; i < size; ++i) {
      printf("row = %d, matrix[%d][%d] = %d, used[i] = %d, match[i] = %d\n", row, row, i, matrix[row][i], static_cast<int>(used[i]), match[i]);
      if (matrix[row][i] >= p && matrix[row][i] - mid <= p && used[i] == false) {
        printf("    used[%d] = %d\n", i, true);
        used[i] = true;
        if (match[i] == -1 || DFS(match[i])) {
          printf("    match[%d] = %d,  return true\n", i, row);
          match[i] = row;
          return true;
        }
      }
    }

    cout << "return false \n";
    return false;
  }

  bool Hungry() {
    match = vector<int>(size, -1);
    for (int i = 0; i < size; ++i) {
      cout << "reset used bits\n";
      used = vector<bool>(size, false);
      if (!DFS(i)) {
        return false;
      }
    }
    return true;
  }

  int Compute() {
    int l = 0;
    int r = mmax - mmin;

    while (l <= r) {
      mid = (l + r) >> 1;
      cout << "mid = " << mid << endl << endl;
      bool found = false;
      for (p = mmin; p <= mmax - mid; ++p) {
        cout << "p = " << p << ", p + mid = " << p + mid << endl;
        if (Hungry()) {
          found = true;
          break;
        }
      }
      if (found) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return res;
  }


private:
  vector<vector<int>> matrix;
  vector<int> match;
  vector<bool> used;
  const int INF = 0x3f3f3f3f;
  int size = 0;
  int p = 0;
  int row = 0;
  int mid = 0;
  int mmax = -INF;
  int mmin = INF;
  int res = 0;

public:
  static void run() {
    vector<vector<int>> v = {{1, 1, 1},
                             {2, 2, 2},
                             {3, 3, 3}};
    cout << Solution(v).Compute() << endl;
  }
};


#endif //LEETCODE_HDU_22366_ERFENTU_H

