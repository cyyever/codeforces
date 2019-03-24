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

int main() {
  size_t k;
  std::cin >> k;

  uint64_t substr_cnt=0;
  if(k==0) {
    uint64_t zero_cnt=0;
    while(true) {
      char c;
      std::cin>> c;
      if(std::cin.eof()) {
        c='1';
      }

      if(c=='0') {
        zero_cnt++;
      } else {
        substr_cnt+=(zero_cnt+1)*zero_cnt/2;
        zero_cnt=0;
      }
      if(std::cin.eof()) {
        break;
      }
    }
    std::cout<<substr_cnt;
    return 0;
  }
  std::string s;
  s.reserve(1000000);
  while(true) {
    char c;
    std::cin>> c;
    if(std::cin.eof()) {
      break;
    }
    s.push_back(c);
  }

  std::vector<uint64_t> suffix_cnts(k+1,0);
  std::vector<uint64_t> substr_cnts(k+1,0);

  for(auto it=s.rbegin();it!=s.rend();it++) {
    for(size_t i=0;i<=k;i++) {
      if(*it=='0') {
        if(i==0) {
        substr_cnts[i]=suffix_cnts[i]+1;
        } else {
        substr_cnts[i]=suffix_cnts[i];
        }
      } else {
        if(i!=0) {
        substr_cnts[i]=suffix_cnts[i-1];
        if(i==1) {
          substr_cnts[i]++;
        }
        } else {
        substr_cnts[i]=0;
        }
      }
    }
    substr_cnt+=substr_cnts[k];
    std::swap(suffix_cnts,substr_cnts);
  }

  std::cout<<substr_cnt;
  return 0;

}
