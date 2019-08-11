//
// Created by lelezi on 2019-08-09.
//

#ifndef LEETCODE_112_PATH_SUM_H
#define LEETCODE_112_PATH_SUM_H

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }

    return help(root, sum, 0);
  }

  bool help(TreeNode *root, int sum, int pre) {
    if (root == nullptr) {
      return false;
    }

    if (root->right == nullptr && root->left == nullptr) {
      if (pre + root->val == sum) {
        return true;
      } else {
        return false;
      }
    }

    return help(root->left, sum, pre + root->val) ||
           help(root->right, sum, pre + root->val);
  }


  static void run() {
    auto a = TreeNode(1);
    auto b = TreeNode(2);
    auto c = TreeNode(3);
    auto d = TreeNode(-2);
    auto e = TreeNode(6);
    auto f = TreeNode(-3);
    auto g = TreeNode(9);

    d.left = &b;
    d.right = &f;
    //b.left = &a;
    //b.right = &c;
    //f.left = &e;
    //.right = &g;
    cout << Solution().hasPathSum(&d, -5);
  }
};

#endif //LEETCODE_112_PATH_SUM_H
