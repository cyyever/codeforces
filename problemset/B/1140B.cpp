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
  size_t t;
  std::cin >> t;
  for (size_t i=0;i<t;i++) {
  size_t n;
  std::cin >> n;

  size_t start_less_symbol_cnt=0;
  size_t end_greater_symbol_cnt=0;
  bool count_start_less_symbol=true;
  bool count_end_greater_symbol=false;
  for (size_t j=0;j<n;j++) {
    char c;
    std::cin >> c;
    if(c=='<') {
      if (count_start_less_symbol) {
        start_less_symbol_cnt++;
      }
      count_end_greater_symbol=false;
      end_greater_symbol_cnt=0;
    } else {
      count_start_less_symbol=false;
      if(!count_end_greater_symbol) {
        count_end_greater_symbol=true;
      } 
      end_greater_symbol_cnt++;
    }
  }
  if(n==1) {
    std::cout<<0<<'\n';
  } else {
    std::cout<<std::min(start_less_symbol_cnt,end_greater_symbol_cnt)<<'\n';
  }
}
  return 0;
  }
