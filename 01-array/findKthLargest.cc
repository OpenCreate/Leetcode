/*
 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，
你需要找的是数组排序后的第 k 个最大的元素，
而不是第 k 个不同的元素。
*/

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    //思路1：使用大堆
    priority_queue<int> q;
    for (auto x : nums) q.push(x);
    for (int i = 1; i < k; ++i) {
      q.pop();
    }

    return q.top();
  }
};

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    //思路2：使用k个元素的小堆，用来过滤小元素
    priority_queue<int, vector<int>, greater<int> > q(nums.begin(),
                                                      nums.begin() + k);
    for (int i = k; i < nums.size(); ++i) {
      if (q.top() < nums[i]) {
        q.pop();
        q.push(nums[i]);
      }
    }

    return q.top();
  }
};

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    //思路3：使用快速排序的partition思想，比使用堆要复杂很多
    return selectK(nums, 0, nums.size() - 1, nums.size() - k);
  }

  //返回数组中的第K小元素
  int selectK(vector<int> arr, int l, int r, int k) {
    int p = partition(arr, l, r);
    if (p == k)
      return arr[k];
    else if (p < k)
      return selectK(arr, p + 1, r, k);
    return selectK(arr, l, p - 1, k);
  }

  //对数组进行partition，返回枢纽元素归为后所在的索引
  int partition(vector<int>& arr, int l, int r) {
    int p = (rand() % (r - l + 1)) + l;
    swap(arr[l], arr[p]);
    //[l+1..i-1] <= v  [j+1...r] >= v
    int i = l + 1, j = r;
    while (true) {
      while (i <= j && arr[i] < arr[l]) {
        i++;
      }
      while (j >= i && arr[j] > arr[l]) {
        j--;
      }
      if (i >= j) break;
      swap(arr[i], arr[j]);
      i++;
      j--;
    }

    swap(arr[l], arr[j]);  //枢纽归位
    return j;
  }
};