/*!
 * \file 1249A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/486/A
 * \author cyy
 */

#include <cinttypes>
#include <iostream>

int main(void) {
  size_t q;
  std::cin >> q;
  for (size_t i = 0; i < q; i++) {
    size_t n;
    std::cin >> n;
    bool flags[102]{};
    size_t cnt = 1;
    for (size_t j = 0; j < n; j++) {
      int a;
      std::cin >> a;
      flags[a] = true;
      if (cnt == 1 && (flags[a - 1] || flags[a + 1])) {
        cnt = 2;
      }
    }
    std::cout << cnt << std::endl;
  }

  return 0;
}
