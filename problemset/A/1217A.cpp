/*!
 * \file 1217A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1217/A
 * \author cyy
 */

#include <iostream>

int main(void) {
  size_t T;
  std::cin >> T;

  int64_t str, intelligence, exp;
  for (size_t i = 0; i < T; i++) {
    std::cin >> str >> intelligence >> exp;
    size_t count = 0;
    if (intelligence + exp < str) {
      count = exp + 1;
    } else {
      auto min_exp = (intelligence + exp - str) / 2 + 1;
      if (min_exp > exp) {
        count = 0;
      } else {
        count = exp - min_exp + 1;
      }
    }
    std::cout << count << std::endl;
  }
  return 0;
}
