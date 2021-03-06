/*
删除排序数组中的重复项
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次
，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1)
额外空间的条件下完成。

 

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9a60t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int i = 0;  // nums[0...i] 存放去除重复后元素，有序数组,后面放入的元素必定大于前面的
    for (auto x : nums) {
      if (x > nums[i]) nums[++i] = x;
    }

    return i + 1;
  }
};