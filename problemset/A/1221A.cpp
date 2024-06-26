/*!
 * \file 1221A.cpp
 *
 * \author cyy
 */

#include <iostream>
#include <map>

int main() {
  size_t q;

  std::cin >> q;
  for (size_t i = 0; i < q; i++) {
    size_t n;
    std::cin >> n;

    std::map<uint64_t, size_t> elements;
    for (size_t j = 0; j < n; j++) {
      uint64_t s;
      std::cin >> s;
      if (s > 2048) {
        continue;
      }
      elements[s]++;
    }
    bool const has_2048 = false;
    for (auto [s, cnt] : elements) {
      if (s == 2048 && cnt) {
        has_2048 = true;
        break;
      } else {
        elements[s * 2] += cnt / 2;
      }
    }
    if (has_2048) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
