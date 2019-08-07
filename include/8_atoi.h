//
// Created by lelezi on 2019-08-06.
//

#ifndef LEETCODE_8_ATOI_H
#define LEETCODE_8_ATOI_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int sign = 1;
    stack<char> st;
    int it;
    for (it = 0; it < str.size(); ++it) {
      if (str[it] == ' ') {
        continue;
      } else {
        break;
      }
    }

    if (!IsValid(str[it])) {
      return 0;
    }

    if (IsSign(str[it])) {
      sign = (str[it] == '-' ? -1 : 1);
      ++it;
    }

    for (; it < str.size(); ++it) {
      if (IsZero(str[it])) {
        continue;
      } else {
        break;
      }
    }

    for (; it < str.size(); ++it) {
      if (IsNumber(str[it])) {
        st.push(str[it]);
      } else {
        break;
      }
    }

    if (st.empty()) {
      return 0;
    }

    int index = 1;
    int result = 0;
    while (!st.empty()) {
      char c = st.top();
      st.pop();

      if (INT_MAX / index < (c - '0')) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }
      int tmp = (c - '0') * index;

      if (sign == 1 && (INT_MAX - result) < tmp) {
        return INT_MAX;
      } else if (sign == -1 && (INT_MIN + result) >= (tmp * -1)) {
        return INT_MIN;
      }

      result += tmp;

      if (st.empty()) {
        break;
      }

      if (index >= 1 && INT_MAX / index < 10) {
        return (sign == 1) ? INT_MAX : INT_MIN;
      }

      index = 10 * index;
    }

    return result * sign;
  }


  bool IsValid(const char &c) {
    return c == '+' || c == '-' || (c >= '0' && c <= '9');
  }

  bool IsSign(const char &c) {
    return c == '+' || c == '-';
  }

  bool IsNumber(const char &c) {
    return c >= '0' && c <= '9';
  }

  bool IsZero(const char &c) {
    return c == '0';
  }

  bool IsBlankSpace(const char &c) {
    return c == ' ';
  }

public:
  static void run() {
    //string s = "4193 with words";
    //string s = "words and 987";
    //string s = "-91283472332";
    string s = "  0000000000012345678";
    cout << Solution().myAtoi(s) << endl;
  }

};

#endif //LEETCODE_8_ATOI_H


//-1000 > -998   -3