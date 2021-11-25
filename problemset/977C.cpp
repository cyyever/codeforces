/*!
 * \file 977C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/977/C
 * \author cyy
 * \date 2017-06-11
 */

#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <set>

#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename data_type, class compare = std::less<data_type>>
class simple_heap {
public:
  simple_heap() = default;
  void reserve(size_t n) { items.reserve(n); }
  const data_type &top() const {
    assert(!empty());
    return items[0];
  }
  size_t size() const { return items.size(); }
  void pop() {
    if (items.empty()) {
      return;
    }
    if (items.size() == 1) {
      items.clear();
      return;
    }
    std::swap(items[0], items.back());
    items.pop_back();
    heapify_down(0);
  }
  void change_data(size_t idx, data_type data) {
    if (idx >= items.size()) {
      throw std::invalid_argument("not data");
    }

    items[idx] = std::move(data);
    auto new_idx = heapify_up(idx);
    if (idx != new_idx) {
      return;
    }
    heapify_down(idx);
  }
  bool empty() const { return items.empty(); }

  void insert(data_type data) {
    items.emplace_back(std::move(data));
    heapify_up(items.size() - 1);
  }

private:
  size_t heapify_up(size_t i) {
    if (i > 0) {
      auto parent_idx = (i + 1) / 2 - 1;
      if (compare{}(items[i], items[parent_idx])) {
        std::swap(items[i], items[parent_idx]);
        return heapify_up(parent_idx);
      }
    }
    return i;
  }
  void heapify_down(size_t i) {
    auto left_child_index = 2 * (i + 1) - 1;
    auto n = items.size();
    if (left_child_index >= n) {
      return;
    }
    auto min_child_index = left_child_index;
    auto right_child_index = left_child_index + 1;
    if (right_child_index < n) {
      if (compare{}(items[right_child_index], items[left_child_index])) {
        min_child_index = right_child_index;
      }
    }
    if (!compare{}(items[i], items[min_child_index])) {
      std::swap(items[i], items[min_child_index]);
      heapify_down(min_child_index);
    }
  }

private:
  std::vector<data_type> items;
};

int main(int argc, char **argv) {
  uint64_t n, k;
  std::cin >> n >> k;
  size_t heap_size = k + 1;

  simple_heap<uint64_t, std::greater<int64_t>> heap;
  heap.reserve(heap_size);
  for (uint64_t i = 0; i < n; i++) {
    uint64_t a;
    std::cin >> a;
    if (heap.size() < heap_size) {
      heap.insert(a);
    } else {
      if (a < heap.top()) {
        heap.change_data(0, a);
      }
    }
  }
  if (heap.size() < k) {
    std::cout << -1 << std::endl;
    return 0;
  }
  if (heap.size() == k) {
    std::cout << heap.top() << std::endl;
    return 0;
  }
  if (k == 0) {
    if (heap.top() > 1) {
      std::cout << heap.top() - 1 << std::endl;

    } else {

      std::cout << -1 << std::endl;
    }

    return 0;
  }
  auto top1 = heap.top();
  heap.pop();
  auto top2 = heap.top();
  heap.pop();
  assert(top1 >= top2);
  if (top1 != top2) {
    std::cout << top2 << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
  return 0;
}
