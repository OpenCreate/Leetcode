/*
长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ...,
numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n))
时间复杂度的解法。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9gogt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    //暴力法，从[0...n)开始枚举选取符合条件的长度
    int n = nums.size();
    if (n == 0) return 0;
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        if (sum >= target) {
          res = min(res, j - i + 1);
          break;
        }
      }
    }

    return res == INT_MAX ? 0 : res;
  }
};

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    //滑动窗口法，使用两个指针来滑动，窗口内保存两个指针指向区间的所有元素和
    int start = 0;
    int end = 0;
    int res = INT_MAX;  //存放长度结果，初始为最大值
    int sum = 0;
    while (end < nums.size()) {
      sum += nums[end];
      while (sum >= target) {
        res = min(res, end - start + 1);
        sum -= nums[start];
        start++;
      }
      end++;
    }

    return res == INT_MAX ? 0 : res;
  }
};