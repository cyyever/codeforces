/*!
 * \file 20A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/20/A
 * \author cyy
 * \date 2017-06-12
 */

#include <iostream>
#include <string>

int main(void) {
  std::string path, new_path;
  std::cin >> path;
  for (const auto &c : path) {
    if (c == '/' && !new_path.empty() && new_path.back() == '/') {
      continue;
    } else {
      new_path.push_back(c);
    }
  }
  if (new_path.back() == '/' && new_path.size() != 1) {
    new_path.pop_back();
  }

  std::cout << new_path << std::endl;
  return 0;
}
