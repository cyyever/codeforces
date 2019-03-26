/*!
 * \file 118A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/118/A
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  uint64_t n,k;
  std::cin >> n>>k;

  std::cout<<3*n+std::min(k-1,n-k);
  return 0;
}
