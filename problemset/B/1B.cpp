/*!
 * \file 1B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1/B
 * \author cyy
 * \date 2017-06-11
 */

#include <cassert>
#include <cinttypes>
#include <iostream>
#include <string>

int main() {
  size_t n;
  std::cin >> n;
  while (n > 0) {

    std::string coordinates;
    std::cin >> coordinates;

    uint64_t row = 0;
    uint64_t col = 0;

    bool is_RXCY = false;
    if (coordinates[0] == 'R' && std::isdigit(coordinates[1])) {
      size_t i = 2;
      for (; i < coordinates.size() - 1; i++) {
        if (coordinates[i] == 'C' && std::isdigit(coordinates[i + 1])) {
          coordinates[i] = '\0';
          row = std::atoll(coordinates.c_str() + 1);
          col = std::atoll(coordinates.c_str() + i + 1);
          is_RXCY = true;
          break;
        }
      }
    }

    if (!is_RXCY) {
      size_t i = 0;
      while (!std::isdigit(coordinates[i])) {
        auto res = coordinates[i] - 'A' + 1;
        col = col * 26 + res;
        i++;
      }
      row = std::atoll(coordinates.c_str() + i);
      std::cout << "R" << row << "C" << col << std::endl;
    } else {
      std::string col_AZ;
      while (col) {
        auto res = col % 26;
        col /= 26;
        if (res == 0) {
          res = 26;
          col -= 1;
        }
        col_AZ.insert(0, 1, 'A' + res - 1);
      }
      std::cout << col_AZ << row << std::endl;
    }
    n--;
  }
  return 0;
}
