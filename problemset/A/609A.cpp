/*!
 * \file 609A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/609/A
 * \author cyy
 */

#include <algorithm>
#include <cinttypes>
#include <functional>
#include <iostream>
#include <vector>

int main(void) {
  size_t n;
  int64_t m;

  std::cin >> n >> m;

  std::vector<int64_t> a;

  while (n > 0) {

    int64_t b;

    std::cin >> b;
    a.push_back(b);
    n--;
  }

  std::sort(a.begin(), a.end(), std::greater<int64_t>());

  size_t cnt = 0;
  for (auto const &b : a) {

    m -= b;
    cnt++;

    if (m <= 0) {
      break;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
