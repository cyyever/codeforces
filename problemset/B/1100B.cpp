/*!
 * \file 1132.cpp
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
   std::cout.sync_with_stdio(false);
  size_t n;
  std::cin >> n;

  std::vector<uint64_t> divisors;
  divisors.reserve(n);

  for(size_t i=0;i<n;i++) {
    uint64_t a;
    std::cin>>a;
    divisors.push_back(a);
  }

  std::sort(divisors.begin(),divisors.end());

  uint64_t y;
  y=divisors.back();
  divisors.pop_back();

  uint64_t x=0;
  uint64_t last_y_divisor=y;
  for(auto it=divisors.rbegin();it!=divisors.rend();it++) {
    if(y%(*it)==0) {
      if(last_y_divisor==*it) {
        x=*it;
        break;
      }
      last_y_divisor=*it;
    } else {
      x=*it;
      break;
    }
  }

  std::cout<<x<<' '<<y;
  return 0;
}
