//
// Created by lzc on 2021/8/29.
//

#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        const int END_FLAG = 2000;
        queue<Node*> q;
        Node tmp = Node(END_FLAG);
        q.push(root);
        q.push(&tmp);
        while (!(q.size() == 1 && q.front()->val == END_FLAG)) {
            auto n = q.front();
            q.pop();
            if (n->val == END_FLAG) {
                q.push(&tmp);
                continue;
            }
            if (!q.empty() && q.front()->val != END_FLAG) {
                n ->next = q.front();
            }

            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }

        return root;
    }

    static void run() {
        Node g = Node(7);
        Node f = Node(6);
        Node e = Node(5);
        Node d = Node(4);
        Node c = Node(3, &f, &g, nullptr);
        Node b = Node(2, &d, &e, nullptr);
        Node a = Node(1, &b, &c, nullptr);
        auto r = Solution().connect(&a);
        queue<Node*> q;
        q.push(r);
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            auto message = (n->next == nullptr) ? -1 : n->next->val;
            cout << n->val << " " << message << endl;
            if (n->left) {
                q.push(n->left);
            }
            if (n->right) {
                q.push(n->right);
            }
        }
    }
};