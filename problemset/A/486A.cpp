/*!
 * \file 486A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/486/A
 * \author cyy
 */

#include <cinttypes>
#include <iostream>

int main(void) {
  uint64_t n;
  std::cin >> n;

  if (n & 1) {
    std::cout << "-" << n - n / 2 << std::endl;
  } else {
    std::cout << n / 2 << std::endl;
  }
  return 0;
}
