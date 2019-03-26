/*!
 * \file 41A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/41/A
 * \author cyy
 */

#include <iostream>
#include <string>

int main(void) {
  std::string s, t;
  std::cin >> s >> t;
  if (s.size() != t.size()) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] != t[s.size() - 1 - i]) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }
  std::cout << "YES" << std::endl;
  return 0;
}
