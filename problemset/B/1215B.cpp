/*!
 * \file 1215B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1215/B
 * \author cyy
 * \date 2017-06-11
 */

#include <cinttypes>
#include <iostream>

int main(void) {
  size_t n;
  std::cin >> n;
  uint64_t positive_cnt = 0;
  uint64_t negative_cnt = 0;
  uint64_t cur_positive_cnt = 0;
  uint64_t cur_negative_cnt = 0;
  int64_t a;
  for (size_t i = 0; i < n; i++) {
    std::cin >> a;

    if (a > 0) {
      cur_positive_cnt++;
    } else {
      auto tmp = cur_negative_cnt;
      cur_negative_cnt = cur_positive_cnt + 1;
      cur_positive_cnt = tmp;
    }
    positive_cnt += cur_positive_cnt;
    negative_cnt += cur_negative_cnt;
  }
  std::cout << negative_cnt << ' ' << positive_cnt;
  return 0;
}
