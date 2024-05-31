/*!
 * \file 792C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/792/C
 * \author cyy
 * \date 2017-06-11
 */

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  size_t k = 0;
  std::cin >> k;

  std::vector<uint64_t> substr_cnts(k + 1, 0);

  uint64_t substr_cnt = 0;
  while (true) {
    char c = 0;
    std::cin >> c;

    if (std::cin.eof()) {
      break;
    }
    if (c == '0') {
      substr_cnts[0]++;
    } else {
      substr_cnts[0]++;
      for (size_t i = k; i >= 1; i--) {
        substr_cnts[i] = substr_cnts[i - 1];
      }
      /*
      if(k>0) {
      substr_cnts[1]++;
      }
      */
      substr_cnts[0] = 0;
    }
    substr_cnt += substr_cnts[k];
  }

  std::cout << substr_cnt;
  return 0;
}
