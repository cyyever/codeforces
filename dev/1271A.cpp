/*!
 * \file 1271A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1271/A
 * \author cyy
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <set>

int main() {
  uint64_t a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;

  uint64_t cost = 0;
  if (e > f) {
    auto first_type_number = std::min(a, d);
    a -= first_type_number;
    d -= first_type_number;
    cost += e * first_type_number;
  }
  auto second_type_num = std::min(std::min(b, c), d);
  b -= second_type_num;
  c -= second_type_num;
  d -= second_type_num;
  cost += f * second_type_num;
  auto first_type_number = std::min(a, d);
  cost += e * first_type_number;

  std::cout << cost << std::endl;

  return 0;
}
