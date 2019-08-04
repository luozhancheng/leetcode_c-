//
// Created by lelezi on 2019-08-03.
//

#ifndef LEETCODE_20_VALID_PARENTHESES_H
#define LEETCODE_20_VALID_PARENTHESES_H

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    for (auto c : s) {
      if (isPrefix(string(1, c))) {
        st.push(string(1, c));
      } else {
        if (st.empty()) {
          st.push(string(1, c));
          break;
        }
        if (st.top() == m[string(1, c)]) {
          st.pop();
        } else {
          break;
        }
      }
    }
    return st.empty();
  }

  bool isPrefix(string s) {
    return s == "{" || s == "(" || s == "[";
  }

  unordered_map<string, string> m = {{"}", "{"},
                                     {")", "("},
                                     {"]", "["}};
  stack<string> st;



  static void run()
  {
    string s = "{}[]{}";
    cout << Solution().isValid(s);
  }

};

#endif //LEETCODE_20_VALID_PARENTHESES_H
