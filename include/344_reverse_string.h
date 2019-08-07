//
// Created by lelezi on 2019-08-06.
//

#ifndef LEETCODE_344_REVERSE_STRING_H
#define LEETCODE_344_REVERSE_STRING_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end) {
      char c = s[begin];
      s[begin] = s[end];
      s[end] = c;
      ++begin;
      --end;
    }
  }


public:
  static void run() {
    vector<char> v = {'h','e','l','l','o'};
    Solution().reverseString(v);
    for (auto c : v) {
      cout << c << "";
    }
  }
};

#endif //LEETCODE_344_REVERSE_STRING_H
