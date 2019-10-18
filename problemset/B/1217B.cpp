/*!
 * \file 1712B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1712/B
 * \author cyy
 */

#include <algorithm>
#include <iostream>
#include <utility>

int main(void) {
  size_t t;
  std::cin >> t;

  for (size_t i = 0; i < t; i++) {
    size_t n;
    int64_t x;
    std::cin >> n >> x;
    int64_t max_d = 0;
    int64_t max_hurt = INT64_MIN;
    for (size_t j = 0; j < n; j++) {
      int64_t d, h;
      std::cin >> d >> h;
      max_d = std::max(d, max_d);
      max_hurt = std::max(max_hurt, d - h);
    }
    if (max_d >= x) {
      std::cout << 1 << std::endl;
    } else if (max_hurt <= 0) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << ((x - max_d + max_hurt - 1) / max_hurt) + 1 << std::endl;
    }
  }
  return 0;
}
