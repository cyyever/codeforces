/*!
 * \file 118A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/118/A
 * \author cyy
 * \date 2017-06-12
 */

#include <cstring>
#include <iostream>
#include <string>

int main(void) {
  std::string s;
  std::string t;
  std::cin >> s;
  for (auto c : s) {
    if (c >= 'A' && c <= 'Z') {
      c = c - 'A' + 'a';
    }
    if (strchr("aoyeui", c)) {
      continue;
    }
    t.push_back('.');
    t.push_back(c);
  }

  std::cout << t << std::endl;
  return 0;
}
