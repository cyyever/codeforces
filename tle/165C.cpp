/*!
 * \file 792C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/792/C
 * \author cyy
 * \date 2017-06-11
 */

#include <cinttypes>
#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
  size_t k;
  std::cin >> k;

  size_t one_cnt=0;
  uint64_t substr_cnt=0;
  std::vector<uint64_t> zero_substrings;
  zero_substrings.reserve(k);
  zero_substrings.push_back(0);

  while(true) {
    char c;
    std::cin>> c;
    if(std::cin.eof()) {
      c='1';
    }

    if(c=='0') {
      zero_substrings.back()++;
    } else {
      if(one_cnt==k) {
        if(k==0) {
        substr_cnt+=(zero_substrings[0]+1)*zero_substrings[0]/2;
        } else {
        substr_cnt+=(zero_substrings[0]+1)*(zero_substrings.back()+1);
        }
        zero_substrings.erase(zero_substrings.begin());
        one_cnt--;
      } 
      one_cnt++;
      zero_substrings.push_back(0);
    }
    if(std::cin.eof()) {
      break;
    }
  }
    std::cout<<substr_cnt;

  return 0;
}
