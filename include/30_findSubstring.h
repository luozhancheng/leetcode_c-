//
// Created by lzc on 2021/9/24.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> m1;
        for (const auto &it : words) {
            m1[it] += 1;
        }

        vector<int> result;
        int wordLen = words[0].size();
        for (int i = 0; i < s.size() - words.size() * wordLen + 1; ++i) {
            int nums = 0;
            unordered_map<string, int> m2;
            while (nums < words.size()) {
                string sub = s.substr(i + nums * wordLen, wordLen);
                if (m1.find(sub) == m1.end() || m2[sub] >= m1[sub]) {
                    break;
                }
                m2[sub] += 1;
                nums++;
            }
            if (nums == words.size()) {
                result.push_back(i);
            }
        }

        return result;
    }


public:
    static void run()
    {
        string s("barfoothefoobarman");
        string s1("wordgoodgoodgoodbestword");
        string s2("barfoofoobarthefoobarman");
        vector<string> words = {"foo","bar"};
        vector<string> words1 = {"word","good","best","word"};
        vector<string> words2 = {"bar","foo","the"};
//        auto r = Solution().findSubstring(s2, words2);
//        auto r = Solution().findSubstring(s1, words1);
        auto r = Solution().findSubstring(s, words);
        for (const auto &it : r) {
            cout << it << ", ";
        }
        cout << endl;
    }

};
