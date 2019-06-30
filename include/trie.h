//
// Created by lelezi on 2019-04-27.
//

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H

#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode() {
        this->val = 0;
        this->isWord = false;
    }
    TrieNode(char val) {
        this->val = val;
        this->isWord = false;
    }
    ~TrieNode() {
        cout << "begint destruct val = " << this->val << endl;
        for (TrieNode* t : this->child) {
            if (t != nullptr)
                delete t;
                t = nullptr;
        }
        cout << "end destruct val = " << this->val << endl;
    }


    char val;
    bool isWord;
    TrieNode* child[26] = {nullptr};
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        if (root != nullptr) {
            delete root;
            root = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* t = root;
        for (char c : word) {
            if (t->child[c - 'a'] == nullptr) {
                t->child[c - 'a'] = new TrieNode(c);
            }
            t = t->child[c - 'a'];
        }
        t->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* t = root;
        for (char c : word) {
            if (t->child[c - 'a'] == nullptr) {
                return false;
            }
            t = t->child[c - 'a'];
        }

        return t->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for (char c : prefix) {
            if (t->child[c - 'a'] == nullptr) {
                return false;
            }
            t = t->child[c - 'a'];
        }

        return true;
    }

private:
    TrieNode* root = {nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/

class Solution {
public:
    static void run() {
        Trie *obj = new Trie();
        obj->insert("apple");
        bool param_2 = obj->search("app");
        bool param_3 = obj->startsWith("app");

        std::cout << "param_2 = " << param_2 << std::endl;
        std::cout << "param_3 = " << param_3 << std::endl;
        delete obj;
    }
};


#endif //LEETCODE_TRIE_H
