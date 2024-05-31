/*!
 * \file 1136D.cpp
 *
 * \brief http://codeforces.com/problemset/problem/1136/D
 * \author cyy
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
  size_t n, m;
  std::cin >> n >> m;

  if (m == 0) {
    std::cout << 0;
    return 0;
  }

  std::vector<uint32_t> pupils;
  pupils.reserve(n);
  for (size_t i = 0; i < n; i++) {
    uint32_t a;
    std::cin >> a;
    pupils.push_back(a);
  }

  auto nastya = pupils.back();

  std::unordered_map<uint32_t, std::unordered_set<uint32_t>> relations;
  std::unordered_set<uint32_t> nastya_front_pupils;

  for (size_t i = 0; i < m; i++) {
    uint32_t a, b;
    std::cin >> a >> b;
    if (b == nastya) {
      nastya_front_pupils.emplace(a);
    } else {
      relations[a].insert(b);
    }
  }

  size_t cnt = 0;
  auto last_it = pupils.rbegin() + 1;
  auto cur_it = last_it;
  std::vector<uint32_t> front_pupils;
  while (cur_it != pupils.rend()) {
    bool flag = true;
    if (nastya_front_pupils.find(*cur_it) != nastya_front_pupils.end()) {
      auto const &relation = relations[*cur_it];
      for (auto &pupil : front_pupils) {
        if (relation.find(pupil) == relation.end()) {
          flag = false;
          break;
        }
      }
      if (flag) {
        cnt++;
        std::swap(*cur_it, *last_it);
        last_it++;
      }
    } else {
      flag = false;
    }

    if (!flag) {
      front_pupils.push_back(*cur_it);
    }
    cur_it++;
  }
  std::cout << cnt;
  return 0;
}
