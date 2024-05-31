/*!
 * \file 1130A.cpp
 *
 * \author cyy
 */

#include <iostream>

int main() {
  size_t n;

  std::cin >> n;

  size_t threshhold = (n + 1) / 2;

  size_t positive_num = 0;
  size_t negative_num = 0;
  int64_t a;
  for (size_t i = 0; i < n; i++) {
    std::cin >> a;
    if (a > 0) {
      positive_num++;
    } else if (a < 0) {
      negative_num++;
    }
  }
  if (positive_num >= threshhold) {
    std::cout << 1 << std::endl;
  } else if (negative_num >= threshhold) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
