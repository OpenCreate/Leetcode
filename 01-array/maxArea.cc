/*
盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画
n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x96n4v/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
 public:
  int maxArea(vector<int>& height) {
    // TODO:计算当前容积然后移动较短的板，更新此值。
    int l = 0;
    int r = height.size() - 1;
    int maxValue = 0;
    while (l < r) {
      maxValue = max((r - l) * min(height[r], height[l]), maxValue);
      if (height[l] < height[r])
        l++;
      else
        r--;
    }

    return maxValue;
  }
};