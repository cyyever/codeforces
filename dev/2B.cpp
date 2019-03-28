/*!
 * \file 118A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/118/A
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

int64_t get_zero_cnt(const std::pair<int64_t,int64_t> &a) {
  if(a.first==-1) {
    return 1;
  }
  return std::min(a.first,a.second);
}

std::pair<int64_t,int64_t> add_pair(const std::pair<int64_t,int64_t> &a,const std::pair<int64_t,int64_t> &b)  {
  if(a.first==-1) {
    return a;
  }
    if( b.first==-1) {
      return b;
    }
  return {a.first+b.first,a.second+b.second};
}

int main(void) {
  std::ios::sync_with_stdio(false);
  size_t n;
  std::cin >> n;

  std::vector<std::vector<std::pair<int64_t,int64_t>>>  matrix;

  std::pair<size_t,size_t> zero_index;
    bool has_zero=false;
  for(size_t i=0;i<n;i++) {
    matrix.emplace_back();
    for(size_t j=0;j<n;j++) {
      int64_t a;
      std::cin>>a;

      if(a!=0) {
        int64_t two_cnt=0;
        int64_t factor=2;

        while(a%factor==0) {
          two_cnt++;
          factor*=2;
        }
        factor=5;
        int64_t five_cnt=0;

        while(a%factor==0) {
          five_cnt++;
          factor*=5;
        }
        matrix[i].emplace_back(two_cnt,five_cnt);
      } else {
        if(!has_zero) {
          has_zero=true;
          zero_index.first=j;
          zero_index.second=i;
        }
        matrix[i].emplace_back(-1,-1);
      }
    }
  }

  std::vector<std::vector<std::string>> route(n,std::vector<std::string>(n));
  for (size_t k=1;k<2*n-1;k++) {
    size_t i=0;
    if(k+1>=n) {
      i=k+1-n;
    }
    i=std::min(i,n-1);
    size_t j=k-i;
    while(true) {
      int64_t zero_cnt=INT64_MAX;
      std::string new_route;
       std::pair<int64_t,int64_t> sum;
      if(i>0) {
        auto tmp=add_pair(matrix[i-1][j],matrix[i][j]);
        int64_t new_zero_cnt=get_zero_cnt(tmp);
        if(new_zero_cnt<zero_cnt) {
          new_route=route[i-1][j]+'D';
          zero_cnt=new_zero_cnt;
          sum=std::move(tmp);
        }
      }
      if(j>0) {
        auto tmp=add_pair(matrix[i][j-1],matrix[i][j]);
        int64_t new_zero_cnt=get_zero_cnt(tmp);
        if(new_zero_cnt<zero_cnt || (new_zero_cnt==zero_cnt && tmp.first+tmp.second<sum.first+sum.second)) {
          new_route=route[i][j-1]+'R';
          zero_cnt=new_zero_cnt;
          sum=std::move(tmp);
        }
      }
      matrix[i][j]=std::move(sum);
      route[i][j]=std::move(new_route);
      i++;
      if(i==n) {
        break;
      }
      if(j==0) {
        break;
      }
      j--;
    }
  }

  auto cnt=get_zero_cnt(matrix[n-1][n-1]);
  if (cnt>1 && has_zero) {
    std::cout<<1<<std::endl;
    for(size_t i=0;i<zero_index.first;i++) {
      std::cout<<'R';
    }
    for(size_t j=0;j<zero_index.second;j++) {
      std::cout<<'D';
    }
    for(size_t i=zero_index.first;i+1<n;i++) {
      std::cout<<'R';
    }
    for(size_t i=zero_index.second;i+1<n;i++) {
      std::cout<<'D';
    }
    return 0;
  }
  std::cout<<cnt<<std::endl;
  std::cout<<route[n-1][n-1];
  return 0;
}
