/*!
 * \file 792C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/792/C
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <iostream>
#include <string>

int main(void) {
  std::string n;

  std::cin >> n;

  int sum_remainder = 0;

  int index[3][2] = {{-1, -1}, {-1, -1}, {-1, -1}};

  for (int i = 0; i < (int)n.size(); i++) {
    auto remainder = (n[i] - '0') % 3;
    sum_remainder += remainder;

    if (remainder != 0) {
      index[remainder][1] = index[remainder][0];
      index[remainder][0] = i;
    }
  }

  sum_remainder %= 3;

  if (sum_remainder != 0) {
    auto max_remainder_index =
        std::max(index[sum_remainder][0], index[sum_remainder][1]);

    if (index[3 - sum_remainder][0] == -1) {
      if (max_remainder_index == -1) {
        std::cout << -1 << std::endl;
        return 0;
      }
      n.erase(n.begin() + max_remainder_index);
    } else {
      if (max_remainder_index == -1 ||
          (max_remainder_index == 0 && n[1] == '0')) {
        n.erase(n.begin() + index[3 - sum_remainder][0]);
        n.erase(n.begin() + index[3 - sum_remainder][1]);
      } else {
        n.erase(n.begin() + max_remainder_index);
      }
    }
  }

  while (n.size() > 1 && n[0] == '0') {
    n.erase(n.begin());
  }
  if (n.empty()) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << n << std::endl;
  }
  return 0;
}
