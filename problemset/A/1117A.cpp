/*!
 * \file 118A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/118/A
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

int main(void) {
  std::ios::sync_with_stdio(false);
  size_t n;
  std::cin >> n;
  uint64_t a;
  uint64_t max_element=0;
  uint64_t last_element=0;
  size_t len=0;
  size_t max_len=1;
  for (size_t i=0;i<n;i++) {
      std::cin>>a;
    if(a>max_element) {
      max_element=a;
      len=1;
      max_len=1;
    } else if(a==max_element && last_element==a) {
      len++;
      max_len=std::max(len,max_len);
    } else {
      len=1;
    }
    last_element=a;
  }

  std::cout << max_len << std::endl;
  return 0;
}
