//
// Created by lelezi on 2019-08-08.
//

#ifndef LEETCODE_98_VALIDATE_BTREE_H
#define LEETCODE_98_VALIDATE_BTREE_H

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
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    if (!isValidBST(root->left)) {
      return false;
    }

    if (pre != nullptr && root->val <= pre->val) {
      return false;
    }

    pre = root;

    return isValidBST(root->right);
  }

  TreeNode *pre = nullptr;

/*
  bool help(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (root == nullptr) {
      return true;
    }

    if (min != nullptr && root->val <= min->val) {
      return false;
    }

    if (max != nullptr && root->val >= max->val) {
      return false;
    }

    return help(root->left, min, root) && help(root->right, root, max);
  }
*/


  static void run() {
    auto a = TreeNode(1);
    auto b = TreeNode(2);
    auto c = TreeNode(3);
    auto d = TreeNode(4);
    auto e = TreeNode(6);
    auto f = TreeNode(7);
    auto g = TreeNode(9);

    d.left = &b;
    d.right = &f;
    b.left = &a;
    b.right = &c;
    f.left = &e;
    f.right = &g;

    cout << Solution().isValidBST(&d);

  }
};

#endif //LEETCODE_98_VALIDATE_BTREE_H
