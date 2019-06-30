//
// Created by lelezi on 2019-05-18.
//

#ifndef LEETCODE_TRIANGLE_H
#define LEETCODE_TRIANGLE_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> mini = triangle[triangle.size() - 1];
    for (int i = triangle.size() - 2; i >= 0; i--) {
      for (int j = 0; j < triangle[i].size(); j++) {
        mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
      }
    }

    return mini[0];
  }


  static void run() {
    vector<vector<int>> v = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    int ret = Solution().minimumTotal(v);
    std::cout << "ret = " << ret << std::endl;
  }
};


#endif //LEETCODE_TRIANGLE_H
