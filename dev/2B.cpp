/*!
 * \file 118A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/118/A
 * \author cyy
 */

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

class number final {
public:
  explicit number(uint64_t a) {
    if (a == 0) {
      two_cnt = 1;
      five_cnt = 1;
      is_zero = true;
      return;
    }

    uint64_t factor = 2;

    while (a % factor == 0) {
      two_cnt++;
      factor *= 2;
    }
    factor = 5;
    while (a % factor == 0) {
      five_cnt++;
      factor *= 5;
    }
  }

  number(const number &) = default;
  [[nodiscard]] uint64_t get_zero_count() const {
    return std::min(two_cnt, five_cnt);
  }
  void multiply_number(const number &rhs) {
    if (is_zero) {
      return;
    }
    if (rhs.is_zero) {
      two_cnt = rhs.two_cnt;
      five_cnt = rhs.five_cnt;
      is_zero = true;
      return;
    }
    two_cnt += rhs.two_cnt;
    five_cnt += rhs.five_cnt;
  }

  [[nodiscard]] bool compare_zero_count(const number &rhs) const {
    return get_zero_count() < rhs.get_zero_count();
  }
  bool operator<(const number &rhs) const {
    if (is_zero && rhs.is_zero) {
      return true;
    }
    return two_cnt <= rhs.two_cnt && five_cnt <= rhs.five_cnt && !rhs.is_zero;
  }

  bool is_zero{};

private:
  uint64_t two_cnt{};
  uint64_t five_cnt{};
};

int main() {
  std::ios::sync_with_stdio(false);
  size_t n = 0;
  std::cin >> n;

  std::vector<std::vector<number>> matrix;

  for (size_t i = 0; i < n; i++) {
    matrix.emplace_back();
    for (size_t j = 0; j < n; j++) {
      uint64_t a = 0;
      std::cin >> a;
      matrix[i].emplace_back(a);
    }
  }

  std::map<std::pair<size_t, size_t>,
           std::vector<std::pair<std::string, number>>>
      routes;
  routes[{0, 0}].emplace_back("", matrix[0][0]);
  for (size_t k = 1; k < 2 * n - 1; k++) {
    size_t i = 0;
    if (k + 1 >= n) {
      i = k + 1 - n;
    }
    i = std::min(i, n - 1);
    size_t j = k - i;
    auto tmp_routes = std::move(routes);
    while (true) {
      std::vector<std::pair<std::string, number>> my_routes;
      if (i > 0) {
        for (auto [old_route, old_num] : tmp_routes[{i - 1, j}]) {
          old_route += 'D';
          old_num.multiply_number(matrix[i][j]);

          if (!std::any_of(
                  my_routes.begin(), my_routes.end(),
                  [&old_num](const auto &r) { return r.second < old_num; })) {

            my_routes.erase(std::remove_if(my_routes.begin(), my_routes.end(),
                                           [&old_num](const auto &r) {
                                             return old_num < r.second;
                                           }),
                            my_routes.end());
            my_routes.emplace_back(old_route, old_num);
          }
        }
      }

      if (j > 0) {
        for (auto [old_route, old_num] : tmp_routes[{i, j - 1}]) {
          old_route += 'R';
          old_num.multiply_number(matrix[i][j]);

          if (!std::any_of(
                  my_routes.begin(), my_routes.end(),
                  [&old_num](const auto &r) { return r.second < old_num; })) {

            my_routes.erase(std::remove_if(my_routes.begin(), my_routes.end(),
                                           [&old_num](const auto &r) {
                                             return old_num < r.second;
                                           }),
                            my_routes.end());
            my_routes.emplace_back(old_route, old_num);
          }
        }
      }
      routes[{i, j}] = my_routes;
      i++;
      if (i == n) {
        break;
      }
      if (j == 0) {
        break;
      }
      j--;
    }
  }

  auto it = std::min_element(routes[{n - 1, n - 1}].begin(),
                             routes[{n - 1, n - 1}].end(),
                             [](const auto &a, const auto &b) {
                               return a.second.compare_zero_count(b.second);
                             });

  std::cout << it->second.get_zero_count() << '\n';
  std::cout << it->first;
  return 0;
}
