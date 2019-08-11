//
// Created by lelezi on 2019-08-08.
//

#ifndef LEETCODE_104_MAX_DEPTH_TREE_H
#define LEETCODE_104_MAX_DEPTH_TREE_H

#include <iostream>
#include <queue>

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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }



public:
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

    cout << Solution().maxDepth(&d);

  }
};

#endif //LEETCODE_104_MAX_DEPTH_TREE_H
