/*!
 * \file 1369A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1369/A
 * \author cyy
 */
#include <iostream>
int main() {
  size_t t = 0;
  std::cin >> t;
  for (size_t i = 0; i < t; i++) {
    size_t n = 0;
    std::cin >> n;
    if (n % 4 == 0) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
}
