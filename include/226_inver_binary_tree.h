//
// Created by lelezi on 2019-08-08.
//

#ifndef LEETCODE_226_INVER_BINARY_TREE_H
#define LEETCODE_226_INVER_BINARY_TREE_H

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
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return root;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->right, root->left);
    return root;
  }

  static void print2(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    cout << root->val << " ";
    print(root->left);
    print(root->right);
  }


  static void print(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t == nullptr) {
        continue;
      }
      q.push(t->left);
      q.push(t->right);
      cout << t->val << " ";
    }
  }

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

    auto root = Solution().invertTree(&d);
    print(root);
  }
};

#endif //LEETCODE_226_INVER_BINARY_TREE_H
