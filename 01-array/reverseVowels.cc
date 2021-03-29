/*
反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
*/

class Solution {
 public:
  string reverseVowels(string s) {
    // a e i o u
    int i = 0;
    int j = s.size() - 1;
    while (i <= j) {
      while (!isVowel(s[i]) && i < j) i++;
      while (!isVowel(s[j]) && i < j) j--;
      if (i >= j) break;
      swap(s[i], s[j]);
      i++;
      j--;
    }

    return s;
  }

  bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
  }
};