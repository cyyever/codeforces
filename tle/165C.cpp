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
  std::ios::sync_with_stdio(false);
  size_t k;
  std::cin >> k;

  std::vector<uint64_t> preffix_cnts(k+1,0);
  std::vector<uint64_t> substr_cnts(k+1,0);

  uint64_t substr_cnt=0;
    while(true) {
      char c;
      std::cin>> c;

      if(std::cin.eof()) {
        break;
      }

    for(size_t i=0;i<=k;i++) {
      if(c=='0') {
        substr_cnts[i]=preffix_cnts[i];
        if(i==0) {
        substr_cnts[i]++;
        }
      } else {
        if(i==0) {
          substr_cnts[i]=0;
        } else {
          substr_cnts[i]=preffix_cnts[i-1];
          if(i==1) {
            substr_cnts[i]++;
          }
        }
      }
    }
    substr_cnt+=substr_cnts[k];
    std::swap(preffix_cnts,substr_cnts);
  }

  std::cout<<substr_cnt;
  return 0;

}
