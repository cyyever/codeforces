/*!
 * \file 1251C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1251/C
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

int main() {
  size_t t;
  std::cin >> t;

  std::vector<char> odd_chars;
  std::vector<char> even_chars;

  for (size_t n = 0; n < t; n++) {
    size_t i = 0;
    size_t j = 0;
    while (true) {
      int a=getchar();
      bool is_digit = (a!=EOF&& a >= '0' && a <= '9');
      if (is_digit) {
        if ((a - '0') % 2 == 0) {
          even_chars.push_back(a);
        } else {
          odd_chars.push_back(a);
        }
      }
      while (i < odd_chars.size() && j < even_chars.size()) {
        if (odd_chars[i] < even_chars[j]) {
          std::cout << odd_chars[i];
          i++;
          if (i == odd_chars.size()) {
            odd_chars.clear();
            i = 0;
          }
        } else {
          std::cout << even_chars[j];
          j++;
          if (j == even_chars.size()) {
            even_chars.clear();
            j = 0;
          }
        }
      }
      if (!is_digit) {
        for (auto c : odd_chars) {
          std::cout << c;
        }
        odd_chars.clear();
        for (auto c : even_chars) {
          std::cout << c;
        }
        even_chars.clear();
        break;
      }
    }
    std::cout << '\n';
  }
  return 0;
}
