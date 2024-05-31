/*!
 * \file 797B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/797/B
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <iostream>
#include <string>

int main() {
  size_t n;
  int64_t a = 0;
  int64_t max_odd_sum = (int64_t)(INT32_MIN) + 1;
  int64_t max_even_sum = (int64_t)(INT32_MIN);
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    std::cin >> a;

    auto prev_max_even_sum = max_even_sum;
    auto prev_max_odd_sum = max_odd_sum;
    if (a % 2 == 0) {
      max_even_sum =
          std::max(std::max(a, prev_max_even_sum + a), prev_max_even_sum);
      max_odd_sum = std::max(prev_max_odd_sum + a, prev_max_odd_sum);
    } else {
      max_odd_sum =
          std::max(std::max(prev_max_even_sum + a, prev_max_odd_sum), a);
      max_even_sum = std::max(prev_max_even_sum, prev_max_odd_sum + a);
    }
  }
  std::cout << max_odd_sum << std::endl;
  return 0;
}
