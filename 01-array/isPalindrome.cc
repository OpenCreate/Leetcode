/*
验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。
*/

class Solution {
 public:
  bool isPalindrome(string s) {
    //预处理，转换为小写并且移除非数字和字母字符
    string res;
    for (auto c : s) {
      if (isalnum(c)) res += c;
    }

    transform(res.begin(), res.end(), res.begin(), ::tolower);
    int i = 0;
    int j = res.size() - 1;
    while (i <= j) {
      if (res[i] == res[j]) {
        i++;
        j--;
      } else {
        return false;
      }
    }

    return true;
  }
};