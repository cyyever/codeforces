/*!
 * \file 1139.cpp
 *
 * \author cyy
 * \date 2017-06-12
 */

#include <iostream>

int main(void) {
  uint64_t b;
  size_t k;

  std::cin >> b>>k;


  uint64_t is_even=1;
  for (size_t i = 0; i < k; i++) {
    uint64_t a;
    std::cin>>a;

    if(i+1==k) {
      b=1;
    }
    if(a%2==1 && b%2==1) {
      is_even=1-is_even;
    }
  }


  if(is_even) {
    std::cout<<"even";
  } else {
    std::cout<<"odd";
  }
    return 0;
}
