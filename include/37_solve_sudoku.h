//
// Created by lelezi on 2019-08-10.
//

#ifndef LEETCODE_36_VALID_SUDOKU_H
#define LEETCODE_36_VALID_SUDOKU_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
  bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.') {
          for (char k = '1'; k <= '9'; ++k) {
            if (isValid(board, i, j, k)) {
              board[i][j] = k;
              if (solveSudoku(board)) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>> &board, int i, int j, char c) {
    for (int k = 0; k < board.size(); ++k) {
      if (board[i][k] != '.' && board[i][k] == c) {
        return false;
      }
      if (board[k][j] != '.' && board[k][j] == c) {
        return false;
      }

      if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] != '.' &&
          board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c) {
        return false;
      }
    }
    return true;
  }


  static void run() {
    vector<vector<char>> v =
        {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

    vector<vector<char>> v2 =
        {
            {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
            {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
            {'9', '.', '.', '.', '.', '.', '.', '.', '.'}
        };

    cout << Solution().solveSudoku(v2);
  }
};

#endif //LEETCODE_36_VALID_SUDOKU_H
