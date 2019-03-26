/*!
 * \file 1139A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1139/A
 * \author cyy
 */

#include <iostream>

int main(void) {
  size_t n;
  size_t cnt = 0;

  std::cin >> n;
  unsigned char c;
  for (size_t i = 0; i < n; i++) {

    std::cin >> c;
    if ((c - '0') % 2 == 0) {
      cnt += i + 1;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
