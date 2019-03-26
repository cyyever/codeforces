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
#include <map>

int main(void) {
  std::ios::sync_with_stdio(false);
  size_t n,m;
  std::cin >> n>>m;

  if(m==0){
    std::cout<<0;
    return 0;
  }

  std::vector<uint32_t> pupils;
  pupils.reserve(n);
  for(size_t i=0;i<n;i++) {
    uint32_t a;
    std::cin>>a;
    pupils.push_back(a);
  }

  auto nastya=pupils.back();

  auto relation= new bool[n*n]{};

  for(size_t i=0;i<m;i++) {
    uint32_t a,b;
    std::cin>>a>>b;
    relation[(a-1)*n+b-1]=true;
  }

  size_t cnt=0;
  auto last_it=pupils.rbegin();
  auto cur_it=last_it++;
  while(cur_it!=pupils.rend()) {
      if(relation[(*cur_it-1)*n+nastya-1]) {
        bool flag=true;
        for(auto it=last_it+1;it!=cur_it;it++) {
          if(!relation[(*cur_it-1)*n+*it-1]) {
            flag=false;
            break;
          }
        }
        if(flag) {
          cnt++;
        }
        last_it=cur_it;
      }
        cur_it++;
  }

  std::cout<<cnt;
  delete []relation;
  return 0;
}
