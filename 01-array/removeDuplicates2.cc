/*
删除排序数组中的重复项 II
给定一个增序排列数组 nums ，你需要在 原地
删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1)
额外空间的条件下完成。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9nivs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 3) return nums.size();
    //有序序列则插入前和结果序列中的最后一个元素的前一个元素作比较
    int i = 1;  //[0...i]为循环不变量
    for (int j = 2; j < nums.size(); j++) {
      if (nums[j] != nums[i - 1]) {
        nums[++i] = nums[j];
      }
    }

    return i + 1;
  }
};