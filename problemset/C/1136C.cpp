/*!
 * \file 1136C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1136/C
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main(void) {
  size_t n,m;
  std::cin >> n>>m;

  std::map<uint64_t,std::vector<uint64_t>> A_antidiagonals;
  std::map<uint64_t,std::vector<uint64_t>> B_antidiagonals;

  for(size_t i=0;i<n;i++) {
    for(size_t j=0;j<m;j++) {
      uint64_t a;
      std::cin>>a;
      A_antidiagonals[i+j].emplace_back(a);
    }
  }

  for(size_t i=0;i<n;i++) {
    for(size_t j=0;j<m;j++) {
      uint64_t a;
      std::cin>>a;
      auto &antidiagonal=B_antidiagonals[i+j];
      antidiagonal.emplace_back(a);
      auto &A_antidiagonal=A_antidiagonals[i+j];
      if(antidiagonal.size()==A_antidiagonal.size()) {
        std::sort(A_antidiagonal.begin(),A_antidiagonal.end());
        std::sort(antidiagonal.begin(),antidiagonal.end());
        if(antidiagonal!=A_antidiagonal) {
          std::cout<<"NO";
          return 0;
        }
      }
    }
  }

  std::cout<<"YES";
  return 0;
}
