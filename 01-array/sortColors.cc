/*
颜色分类
给定一个包含红色、白色和蓝色，一共 n
个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9wv2h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int i = 0;      //扫描指针
    int zero = -1;  //[0..zero] = 0, [zero+1..i] = 1, [two...n-1] = 2;
    int two = nums.size();

    while (i < two) {
      if (nums[i] == 0) {
        zero++;
        swap(nums[i], nums[zero]);
        i++;

      } else if (nums[i] == 2) {
        two--;
        swap(nums[i], nums[two]);
      } else {
        i++;
      }
    }
  }
};