/*!
 * \file 236A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/236/A
 * \author cyy
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>

int main() {
  bool cnts[26]{};
  char c = 0;
  while (std::cin >> c) {
    cnts[c - 'a'] = true;
  }
  if (std::count(std::begin(cnts), std::end(cnts), true) % 2 == 0) {
    std::cout << "CHAT WITH HER!";
  } else {
    std::cout << "IGNORE HIM!";
  }
  return 0;
}
