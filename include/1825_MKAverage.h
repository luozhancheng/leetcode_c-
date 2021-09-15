//
// Created by lzc on 2021/9/15.
//

#pragma once

#include <set>
#include <queue>
#include <iostream>

using namespace std;

class MKAverage {
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        que.push(num);

        if (low.size() && *low.rbegin() >= num) {
            low.insert(num);
        } else if (hig.size() && *hig.begin() <= num) {
            hig.insert(num);
        } else {
            mid.insert(num);
            sum += num;
        }

        while (low.size() > k) {
            sum += *low.rbegin();
            shiftRight(low, mid);
        }
        while (hig.size() > k) {
            sum += *hig.begin();
            shiftLeft(mid, hig);
        }

        if (que.size() > m) {
            int d = que.front();
            que.pop();
            if (low.find(d) != low.end()) {
                low.erase(low.find(d));
            } else if (hig.find(d) != hig.end()) {
                hig.erase(hig.find(d));
            } else {
                mid.erase(mid.find(d));
                sum -= d;
            }
        }

        if (que.size() >= m) {
            while (low.size() < k) {
                sum -= *mid.begin();
                shiftLeft(low, mid);
            }
            while (hig.size() < k) {
                sum -= *mid.rbegin();
                shiftRight(mid, hig);
            }
        }
    }

    int calculateMKAverage() {
        if (que.size() < m) {
            return -1;
        }
        return sum / (m - 2 * k);
    }

    void shiftRight(multiset<int>& l, multiset<int>& h) {
        h.insert(*l.rbegin());
        l.erase(--l.end());
    }

    void shiftLeft(multiset<int>& l, multiset<int>& h) {
        l.insert(*h.begin());
        h.erase(h.begin());
    }

private:
    uint64_t m;
    uint64_t k;
    uint64_t sum = 0;
    multiset<int> low;
    multiset<int> mid;
    multiset<int> hig;
    queue<int> que;
};

class Solution {
public:
    static void run() {
        MKAverage obj(3, 1);
        obj.addElement(3);        // 当前元素为 [3]
        obj.addElement(1);        // 当前元素为 [3,1]
        obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
        obj.addElement(10);       // 当前元素为 [3,1,10]
        auto ret = obj.calculateMKAverage();
        cout << "ret = " << ret << endl;
    }
};
