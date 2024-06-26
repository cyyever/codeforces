/*!
 * \file 1136A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1136/A
 * \author cyy
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
  size_t n;
  std::cin >> n;

  std::vector<uint64_t> end_pages;
  for (size_t i = 0; i < n; i++) {
    uint64_t s, e;
    std::cin >> s >> e;
    end_pages.emplace_back(e);
  }
  uint64_t mark;
  std::cin >> mark;

  for (auto end_page : end_pages) {
    if (mark > end_page) {
      n--;
    } else {
      break;
    }
  }

  std::cout << n << std::endl;
  return 0;
}
