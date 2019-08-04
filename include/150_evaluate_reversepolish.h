//
// Created by lelezi on 2019-08-04.
//

#ifndef LEETCODE_150_EVALUATE_REVERSEPOLISH_H
#define LEETCODE_150_EVALUATE_REVERSEPOLISH_H

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    for (auto s : tokens) {
      if (set.find(s) != set.end()) {
        int r = st.top();
        st.pop();
        int l = st.top();
        st.pop();
        if (s == "+") {
          st.push(l + r);
        } else if (s == "-") {
          st.push(l - r);
        } else if (s == "*") {
          st.push(l * r);
        } else {
          st.push(l / r);
        }
      } else {
        st.push(stoi(s));
      }
    }
    return st.top();
  }

private:
  stack<int> st;
  unordered_set<string> set = {"+", "-", "*", "/"};

public:
  static void run() {
    vector<string> v = {"2", "1", "+", "3", "*"};
    cout << Solution().evalRPN(v);
  }
};

#endif //LEETCODE_150_EVALUATE_REVERSEPOLISH_H
