/*!
 * \file 977A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/977/A
 * \author cyy
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

int main(void) {
  uint64_t n;
  size_t k;
  std::cin >>n>>k;
  for(size_t i=0;i<k;i++) {
    if(n%10==0) {
      n/=10;
    } else {
      n--;
    }
  }
  std::cout<<n;
  return 0;
}
