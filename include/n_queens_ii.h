//
// Created by lelezi on 2019-05-13.
//

#ifndef LEETCODE_N_QUEENS_II_H
#define LEETCODE_N_QUEENS_II_H


class Solution {
public:
  int totalNQueens(int n) {
    if (n < 1)
      return 0;
    dfs(n, 0, 0, 0, 0);
    return count;
  }

  void dfs(int32_t n, int32_t row, int32_t cols, int32_t pie, int32_t na) {
    if (row >= n) {
      count += 1;
      return;
    }

    // 得到当前所有的空位
    int32_t bits = (~(cols | pie | na)) & ((1 << n) - 1);

    while (bits) {
      // 取得最低位的1
      int32_t p = bits & -bits;
      dfs(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
      // 去掉最低位的1
      bits = bits & (bits - 1);
    }
  }

  int32_t count = {0};




public:
  static void run() {
    int ret = Solution().totalNQueens(8);
    std::cout << "ret = " << ret << std::endl;
  }
};

#endif //LEETCODE_N_QUEENS_II_H
