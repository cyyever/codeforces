/*!
 * \file 1132B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1132/B
 * \author cyy
 * \date 2017-06-11
 */

#include <cassert>
#include <cinttypes>
#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  size_t n;
  std::cin >> n;

  std::vector<uint64_t> sorted_costs;
  sorted_costs.reserve(n);
  uint64_t total_cost=0;
  for (size_t i = 0; i < n; i++) {
    uint64_t cost;
    std::cin >> cost;
    sorted_costs.push_back(cost);
    total_cost+=cost;
  }

  std::sort(sorted_costs.begin(),sorted_costs.end());
  size_t m;

  std::cin >> m;

  for (size_t i = 0; i < m; i++) {
    size_t coupon;
    std::cin >> coupon;
  std::cout <<  total_cost-sorted_costs[n-coupon] << '\n';
  }
  return 0;
}
