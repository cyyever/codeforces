/*!
 * \file 797B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/797/B
 * \author cyy
 * \date 2017-06-11
 */

#include <cinttypes>
#include <iostream>

int main(void) {
  size_t n;
  std::cin >> n;
  int64_t max_even=-1000000000;
  int64_t max_odd=-10000000001;
  while (n > 0) {
    int64_t a;
    std::cin >> a;

    auto b=max_even+a;
    auto c=max_odd+a;

    if(a&1) { //odd 
      max_odd=std::max(std::max(b,a),max_odd);
      max_even=std::max(c,max_even);
    } else {
      max_odd=std::max(c,max_odd);
      max_even=std::max(std::max(b,a),max_even);
    }
    n--;
  }
  std::cout<<max_odd<<std::endl;
  return 0;
}
