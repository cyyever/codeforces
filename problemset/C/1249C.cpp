/*!
 * \file 1249C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1249/C1
 * \brief http://codeforces.com/problemset/problem/1249/C2
 * \author cyy
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

static uint64_t get_good_number(uint64_t a) {
  // find largest power of 3 in answer.
  uint64_t power = 1;
  while (power < a) {
    power *= 3;
  }
  if (power == a) {
    return a;
  }
  auto partial_sum = (power - 1) / 2 + power;
  while (true) {
    if (partial_sum - power >= a) {
      partial_sum -= power;
    }
    if (power == 1) {
      break;
    }
    power /= 3;
  }
  return partial_sum;
}
int main() {
  size_t q;
  std::cin >> q;
  for (size_t i = 0; i < q; i++) {
    uint64_t n;
    std::cin >> n;
    std::cout << get_good_number(n) << std::endl;
  }
  return 0;
}
