/*!
 * \file 572A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/572/A
 * \author cyy
 */

#include <cinttypes>
#include <iostream>

int main() {

  size_t n_a, n_b, k, m;

  int64_t max_k_a = 0, min_m_b = 0;

  std::cin >> n_a >> n_b >> k >> m;

  for (size_t i = 1; i <= n_a; i++) {
    int64_t tmp;
    std::cin >> tmp;
    if (i == k) {
      max_k_a = tmp;
    }
  }

  for (size_t i = 0; i < n_b; i++) {
    int64_t tmp;
    std::cin >> tmp;
    if (i == n_b - m) {
      min_m_b = tmp;
    }
  }

  if (max_k_a < min_m_b) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
