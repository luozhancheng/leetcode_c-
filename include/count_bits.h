//
// Created by lelezi on 2019-05-12.
//

#ifndef LEETCODE_COUNT_BITS_H
#define LEETCODE_COUNT_BITS_H

#include <vector>

using namespace std;


class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> ret(num + 1, 0);

    for (int i = 1; i <= num; i++) {
      ret[i] = ret[i & (i - 1)] + 1;
    }

    return ret;
  }


  static void run() {
    Solution s;



    auto ret = s.countBits(5);

    for_each(begin(ret), end(ret), [](int v){
      std::cout << v << " ";
    });
    cout << "\n";
  }
};

#endif //LEETCODE_COUNT_BITS_H
