/*!
 * \file 59A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/59/A
 * \author cyy
 * \date 2017-06-11
 */

#include <iostream>
#include <string>

int main(void) {
  std::string s;
  std::cin >> s;

  size_t uppercase_cnt = 0;
  for (auto &c : s) {
    if (c >= 'A' && c <= 'Z') {
      uppercase_cnt++;
      c = c - 'A' + 'a';
    }
  }
  if (uppercase_cnt > s.size() - uppercase_cnt) {
    for (auto &c : s) {
      c = c - 'a' + 'A';
    }
  }

  std::cout << s << std::endl;
  return 0;
}
