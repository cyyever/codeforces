/*!
 * \file 1136B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1136/B
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
  uint64_t n,k;
  std::cin >> n>>k;

  std::cout<<3*n+std::min(k-1,n-k);
  return 0;
}
