/*!
 * \file 1100B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1100/B
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
  size_t n,m;
  std::cin >> n>>m;
  std::vector<uint32_t> flags(n,0);
  size_t threshhold=0;


  size_t cnt=0;
  for (size_t j=0;j<m;j++) {
    size_t c;
    std::cin >> c;
    c--;
    flags[c]++;
    if (flags[c]==threshhold+1) {
      cnt++;
      if(cnt==n) {
        std::cout<<'1';
        threshhold++;
        cnt=0;
        for(auto &flag:flags) {
          if (flag>threshhold) {
            cnt++;
          }
        }
        continue;
      }
    } 
    std::cout<<'0';
  }
  return 0;
  }
