/*!
 * \file 1141.cpp
 *
 * \author cyy
 */

#include <iostream>

int main(void) {
  uint64_t m, n;

  std::cin >> n>>m;

  if (m<n || m%n!=0) {
    std::cout << -1<< std::endl;
    return 0;
  }
  auto q=m/n;
  size_t cnt=0;
  while(q!=1) {
    if(q%2==0) {
      q/=2;
      cnt++;
    } else if(q%3==0) {
      q/=3;
      cnt++;
    } else {
    std::cout << -1<< std::endl;
    return 0;
    }
  }
    std::cout << cnt<< std::endl;
    return 0;
}
