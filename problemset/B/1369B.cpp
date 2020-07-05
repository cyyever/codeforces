/*!
 * \file 1369B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1369/B
 * \author cyy
 */
#include <iostream>
#include <string>
int main() {
  size_t n = 0;
  std::cin >> n;
  std::string str;
  for (size_t i = 0; i < n; i++) {
    size_t t = 0;
    std::cin >> t >> str;
    if (str.empty()) {
      std::cout << str << std::endl;
      continue;
    }
    auto one_pos = str.find('1');
    if (one_pos == std::string::npos) {
      std::cout << str << std::endl;
      continue;
    }
    auto zero_pos = str.find('0', one_pos + 1);
    if (zero_pos == std::string::npos) {
      std::cout << str << std::endl;
      continue;
    }
    auto first_one_pos = one_pos;

    while (true) {
      one_pos = str.find('1', zero_pos + 1);
      if (one_pos == std::string::npos) {
        str[first_one_pos] = '0';
        str.resize(first_one_pos + 1);
        std::cout << str << std::endl;
        break;
      }
      zero_pos = str.find('0', one_pos + 1);
      if (zero_pos == std::string::npos) {
        str[first_one_pos] = '0';
        first_one_pos++;
        while (one_pos < str.size()) {
          str[first_one_pos] = '1';
          one_pos++;
          first_one_pos++;
        }
        str.resize(first_one_pos);
        std::cout << str << std::endl;
        break;
      }
    }
  }
}
