/*!
 * \file 1117A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1117/A
 * \author cyy
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

int main() {
  size_t n;
  std::cin >> n;
  uint64_t a;
  uint64_t max_element = 0;
  uint64_t last_element = 0;
  size_t len = 0;
  size_t max_len = 1;
  for (size_t i = 0; i < n; i++) {
    std::cin >> a;
    if (a > max_element) {
      max_element = a;
      len = 1;
      max_len = 1;
    } else if (a == max_element && last_element == a) {
      len++;
      max_len = std::max(len, max_len);
    } else {
      len = 1;
    }
    last_element = a;
  }

  std::cout << max_len << std::endl;
  return 0;
}
