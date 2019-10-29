/*!
 * \file 977C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/977/C
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <set>

int main() {
  int64_t n, k;
  std::cin >> n >> k;

  std::multiset<uint64_t> buf;
  int64_t buf_size = 0;
  for (int64_t i = 0; i < n; i++) {
    uint64_t a;
    std::cin >> a;
    if (buf_size <= k || a <= *(buf.rbegin())) {
      buf.insert(a);
      buf_size++;
      if (buf_size > k) {
        auto rit = buf.crbegin();
        auto it = rit;
        auto b = *it;
        for (int64_t elm_cnt = 0; it != buf.crend() && buf_size - elm_cnt >= k; it++, elm_cnt++) {
          if (*it != b) {
              buf.erase(b);
              buf_size -= elm_cnt;
              break;
          }
        }
      }
    }
  }

  if (k == 0) {
    auto x = *(buf.begin());
    if (x == 1) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << x - 1 << std::endl;
    }
    return 0;
  }

  while (buf_size > k) {
    auto rit = buf.crbegin();
    auto it = rit;
    auto b = *it;
    for (int64_t elm_cnt = 0; it != buf.crend(); it++, elm_cnt++) {
      if (*it != b) {
        buf.erase(b);
        buf_size -= elm_cnt;
        break;
      }
    }
  }
  if (buf_size < k) {
    std::cout << -1 << std::endl;
    return 0;
  }
  std::cout << *(buf.rbegin()) << std::endl;

  return 0;
}
