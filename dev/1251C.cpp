/*!
 * \file 1251C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1251/C
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

int main() {
  size_t t;
  std::cin >> t;

  std::vector<char> odd_chars;
  std::vector<char> even_chars;

  for (size_t i = 0; i < n; i++) {
    char a;
    std::cin >> a;
    if(a>='0'&& a<='9') {
      if((a-'0')%2==0) {
        even_chars.push_back(a);
      } else {
        odd_chars.push_back(a);
      }
    } else {
      size_t i=0;
      size_t j=0;
      while(i<odd_chars.size()&&j<even_chars.size()) {
        if(odd_chars[i]<even_chars[j]) {
          std::cout<<odd_chars[i];
          i++;
        } else {
          std::cout<<even_chars[j];
          j++;
        }
      }
      while(i<odd_chars.size()) {
          std::cout<<odd_chars[i];
          i++;
      }
      while(j<even_chars.size()) {
          std::cout<<even_chars[j];
          j++;
      }
    }
    std::cout<<'\n';
  }
  return 0;
}
