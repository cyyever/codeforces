/*!
 * \file 1A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1/A
 * \author cyy
 */

#include <cinttypes>
#include <iostream>

int main(void) {
  uint64_t n;
  uint64_t m;
  uint64_t a;
  std::cin >> n >> m >> a;
  std::cout << (n + a - 1) / a * ((m + a - 1) / a) << std::endl;
  return 0;
}
