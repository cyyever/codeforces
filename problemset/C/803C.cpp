/*!
 * \file 803C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/803/C
 * \author cyy
 * \date 2017-06-12
 */

#include <algorithm>
#include <cinttypes>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  uint64_t n, k;

  std::cin >> n >> k;

  if (k == 1) {
    std::cout << n << std::endl;
    return 0;
  }

  uint64_t i;
  if (k % 2 == 0) {
    i = k / 2 * (k + 1);
  } else {
    i = (k + 1) / 2 * k;
  }

  for (; i <= n; i++) {
    if (n % i == 0) {
      auto gcd = n / i;
      for (uint64_t a = gcd, j = 1; j <= k - 1; j++, a += gcd) {
        std::cout << a << ' ';
        n -= a;
      }
      std::cout << n << std::endl;
      return 0;
    }
  }

  std::cout << -1 << std::endl;
  return 0;
}
