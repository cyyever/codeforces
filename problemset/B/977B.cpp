/*!
 * \file 977B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/977/B
 * \author cyy
 */

#include <array>
#include <cinttypes>
#include <iostream>

int main(void) {
  std::array<size_t, 26 * 26> cnts{};
  size_t n;
  std::cin >> n;
  char last_c, c;
  std::cin >> last_c;

  size_t max_cnt = 0;
  size_t max_index = 0;
  for (size_t i = 1; i < n; i++) {
    std::cin >> c;
    size_t index =
        static_cast<size_t>(last_c - 'A') * 26 + static_cast<size_t>(c - 'A');
    auto &cnt = cnts[index];
    cnt++;
    if (cnt > max_cnt) {
      max_cnt = cnt;
      max_index = index;
    }
    last_c = c;
  }

  std::cout << static_cast<char>('A' + max_index / 26)
            << static_cast<char>('A' + max_index % 26);
  return 0;
}
