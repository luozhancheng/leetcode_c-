//
// Created by lelezi on 2019-08-03.
//

#ifndef LEETCODE_32_LONGEST_VALID_PARENTHESES_H
#define LEETCODE_32_LONGEST_VALID_PARENTHESES_H

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;



class Solution {
public:
  int longestValidParentheses(string s) {
    int result = 0;

    st.push(-1);

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty()) {
          st.push(i);
        } else {
          result = max(result, i - st.top());
        }
      }
    }
    return result;
  }

private:
  stack<int> st;


public:
  static void run()
  {
    string s = "()(()";
    cout << Solution().longestValidParentheses(s);
  }
};

#endif //LEETCODE_32_LONGEST_VALID_PARENTHESES_H
