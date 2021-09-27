//
// Created by lzc on 2021/9/26.
//

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstring>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void rserialize(TreeNode* root, string &str) {
        if (root == nullptr) {
            str.append("null,");
        } else {
            str.append(to_string(root->val));
            str.push_back(',');
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        rserialize(root, str);
        return str;
    }

    TreeNode* rdeserialize(list<string> &data) {
        if (*data.begin() == "null") {
            data.erase(data.begin());
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(*data.begin()));
        data.erase(data.begin());
        node->left = rdeserialize(data);
        node->right = rdeserialize(data);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        list<string> lstr;
        char *pData = new char[data.size() + 1];
        strncpy(pData, data.data(), data.size());
        pData[data.size()] = 0;

        char *pch = strtok(pData, ",");
        while (pch != nullptr) {
            lstr.insert(lstr.end(), pch);
            pch = strtok(NULL, ",");
        }
        return rdeserialize(lstr);
    }

    static void run() {
        TreeNode n5(5);
        TreeNode n4(4);
        TreeNode n3(3);
        TreeNode n2(2);
        TreeNode n1(1);
        n1.left = &n2;
        n1.right = &n3;
        n3.left = &n4;
        n3.right = &n5;
        auto str = Solution().serialize(&n1);
        cout << "str = " << str << endl;
        auto r = Solution().deserialize(str);
        cout << 10 << endl;
    }
};
