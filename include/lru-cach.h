//
// Created by lelezi on 2019-06-30.
//

#ifndef LEETCODE_LRU_CACH_H
#define LEETCODE_LRU_CACH_H

#include <iostream>
#include <list>
#include <unordered_map>


using namespace std;


class LRUCache {
public:
  LRUCache(int capacity) : capacity(capacity) {

  }

  int get(int key) {
    auto it = data.find(key);
    if (it == data.end()) {
      return -1;
    }
    touch(it);

    return it->second.first;
  }

  void put(int key, int value) {
    auto it = data.find(key);
    if (it != data.end()) {
      touch(it);
    } else {
      if (data.size() == capacity) {
        data.erase(cache.back());
        cache.pop_back();
      }
      cache.push_front(key);
    }
    data[key] = {value, cache.begin()};
  }

private:
  int capacity;
  typedef list<int> LIST;
  typedef pair<int, LIST::iterator> PAIR;
  typedef unordered_map<int, PAIR> UMAP;

  LIST cache;
  UMAP data;


  void touch(const UMAP::iterator& it) {
    int key = it->first;
    cache.erase(it->second.second);
    cache.push_front(key);
    it->second.second = cache.begin();
  }
};

class Solution {
public:
  static void run() {
    LRUCache cache = LRUCache(2 /* 缓存容量 */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout << cache.get(2) << endl;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout << cache.get(1) << endl;       // 返回 -1 (未找到)
    cout << cache.get(3) << endl;       // 返回  3
    cout << cache.get(4) << endl;      // 返回  4
  }
};

#endif //LEETCODE_LRU_CACH_H
