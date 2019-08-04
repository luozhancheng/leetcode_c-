//
// Created by lelezi on 2019-07-28.
//

#ifndef LEETCODE_15_3SUM_H
#define LEETCODE_15_3SUM_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    if (size < 3) {
      return {};
    }

    sort(nums.begin(), nums.end());

    vector<vector<int>> ret;

    for (int i = 0; i < size - 2; ++i) {
      if (nums[i] > 0) {
        break;
      }

      if (i == 0 || nums[i] > nums[i - 1]) {
        int left = i + 1;
        int right = size - 1;
        while (left < right) {
          if (nums[i] + nums[left] + nums[right] == 0) {
            ret.emplace_back(vector<int>({nums[i], nums[left], nums[right]}));
            ++left;
            --right;
            while (left < right && nums[left] == nums[left - 1]) {
              ++left;
            }
            while (left < right && nums[right] == nums[right + 1]) {
              --right;
            }
          } else if (nums[i] + nums[left] + nums[right] > 0) {
            --right;
          } else {
            ++left;
          }
        }
      }
    }

    return ret;
  }



  static void run() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};

    auto ret = Solution().threeSum(v);

    for (auto v : ret) {
      for (auto val : v) {
        cout << val << " ";
      }
      cout << endl;
    }
  }
};

#endif //LEETCODE_15_3SUM_H
