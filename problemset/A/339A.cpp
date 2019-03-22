/*!
 * \file 339A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/339/A
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <vector>

int main(void) {
  std::vector<uint64_t> elems;
  char plus;
  while (std::cin) {
    uint64_t elem = 0;

    std::cin >> elem;
    if (std::cin) {
      elems.push_back(elem);
      std::cin >> plus;
    }
  }
  std::sort(elems.begin(), elems.end());

  std::cout << elems[0];
  for (size_t i = 1; i < elems.size(); i++) {
    std::cout << '+' << elems[i];
  }
  std::cout << std::endl;
  return 0;
}