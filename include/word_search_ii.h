//
// Created by lelezi on 2019-05-03.
//

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

#ifndef LEETCODE_WORD_SEARCH_II_H
#define LEETCODE_WORD_SEARCH_II_H

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
    for (TrieNode* t : this->child) {
      if (t != nullptr)
        delete t;
      t = nullptr;
    }
  }

  char val;
  bool isWord;
  TrieNode* child[26] = {nullptr};
};

class Solution {
public:
  Solution() {
    root = new TrieNode();
  }
  ~Solution() {
    if (root != nullptr) {
      delete root;
      root = nullptr;
    }
  }
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (words.size() == 0) {
      return {};
    }
    if (board.size() == 0 || board[0].size() == 0) {
      return {};
    }

    for (string &word : words) {
      insert(word);
    }

    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (root->child[board[i][j] - 'a'] != nullptr) {
          string cur_word = "";
          dfs(board, i, j, cur_word, root);
        }
      }
    }

    vector<string> ret;
    for (string word : res) {
      ret.push_back(word);
    }

    return ret;
  }

private:
  void dfs(vector<vector<char>>& board, int i, int j, string cur_word, TrieNode* cur_dict) {
    cur_word += board[i][j];
    cur_dict = cur_dict->child[board[i][j] - 'a'];

    if (cur_dict->isWord) {
      res.insert(cur_word);
    }

    char tmp = board[i][j];
    board[i][j] = '@';

    for (int k = 0; k < 4; k++) {
      int x = i + dx[k];
      int y = j + dy[k];
      if (x >= 0 && x < m && y >= 0 && y < n &&
          board[x][y] != '@' && cur_dict->child[board[x][y] - 'a'] != nullptr) {
        dfs(board, x, y, cur_word, cur_dict);
      }
    }

    board[i][j] = tmp;
  }

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

  TrieNode *root;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  set<string> res;
  int m = {0};
  int n = {0};

public:
  static void run() {
    //vector<string> words = {"oath","pea","eat","rain"};
    vector<string> words = {"ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"};
    vector<vector<char>> board =
        {
            {'a', 'b'},
            {'c', 'd'}
        };
    /*vector<vector<char>> board =
        {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
        };*/

    Solution s = Solution();
    vector<string> res = s.findWords(board, words);
    for (string word : res) {
      std::cout << word << std::endl;
    }
  }
};

#endif //LEETCODE_WORD_SEARCH_II_H
