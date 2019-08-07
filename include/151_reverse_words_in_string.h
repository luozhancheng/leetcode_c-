//
// Created by lelezi on 2019-08-06.
//

#ifndef LEETCODE_151_REVERSE_WORDS_IN_STRING_H
#define LEETCODE_151_REVERSE_WORDS_IN_STRING_H

#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    stack<string> st;
    int wordBegin = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        if (wordBegin == -1) {
          continue;
        } else {
          string tmp(s, wordBegin, i - wordBegin);
          st.push(tmp);
          wordBegin = -1;
        }
      } else {
        if (wordBegin == -1) {
          wordBegin = i;
        } else {
          continue;
        }
      }
    }
    if (wordBegin != -1) {
      string tmp(s, wordBegin, s.size() - wordBegin);
      st.push(tmp);
    }

    string result;
    while (!st.empty()) {
      string tmp = st.top();
      st.pop();
      result += tmp;
      if (!st.empty()) {
        result += " ";
      }
    }
    return result;
  }


public:
  static void run() {
    string s = "the sky is blue";
    cout << Solution().reverseWords(s);
  }
};

#endif //LEETCODE_151_REVERSE_WORDS_IN_STRING_H
