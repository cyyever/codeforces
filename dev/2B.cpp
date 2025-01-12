/*!
 * \file 2B.cpp
 *
 * \brief http://codeforces.com/problemset/problem/2/B
 * \author cyy
 */

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

class trace final {
public:
  inline static size_t n = 0;
  explicit trace(const char move, uint64_t a, uint64_t x, uint64_t y) {
    if (moves.empty()) {
      moves.reserve(n);
    }
    moves.push_back(move);
    this->x = x;
    this->y = y;

    if (a == 0) {
      two_cnt = 1;
      five_cnt = 1;
      return;
    }

    while (a % 2 == 0) {
      if (two_cnt.has_value()) {
        two_cnt.value()++;
      } else {
        two_cnt = 1;
      }
      a /= 2;
    }
    while (a % 5 == 0) {
      if (five_cnt.has_value()) {
        five_cnt.value()++;
      } else {
        five_cnt = 1;
      }
      a /= 5;
    }
  }

  trace(const trace &) = default;
  trace(trace &&) = default;
  trace &operator=(const trace &) = default;
  trace &operator=(trace &&) = default;
  [[nodiscard]] std::optional<size_t> get_zero_count() const {
    if (!two_cnt.has_value() && !five_cnt.has_value()) {
      return std::nullopt;
    }
    return std::min(two_cnt, five_cnt);
  }

  auto operator<=>(const trace &rhs) const {
    return get_zero_count() <=> rhs.get_zero_count();
  }

  bool is_zero{};

private:
  std::optional<uint64_t> two_cnt;
  std::optional<uint64_t> five_cnt;
  std::string moves;
  uint64_t x;
  uint64_t y;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> trace::n;
  auto n = trace::n;

  std::vector<std::vector<uint64_t>> matrix;
  matrix.reserve(n);

  for (size_t i = 0; i < n; i++) {
    matrix.emplace_back();
    matrix[i].reserve(n);
    for (size_t j = 0; j < n; j++) {
      uint64_t a = 0;
      std::cin >> a;
      matrix[i].emplace_back(a);
    }
  }

  return 0;
}
