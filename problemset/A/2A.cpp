/*!
 * \file 2A.cpp
 *
 * \brief http://codeforces.com/problemset/problem/2/A
 * \author cyy
 */

#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>

int main(void) {
  std::ios::sync_with_stdio(false);
  size_t n;
  std::cin >> n;

  std::unordered_map<std::string,std::vector<std::pair<size_t,int64_t>>> name_and_score;

  for(size_t i=0;i<n;i++) {
    std::string name;
    int64_t score;
    std::cin>>name;
    std::cin>>score;
    name_and_score[name].emplace_back(i,score);
  }

  std::string max_score_name;
  int64_t max_score=0;
  size_t max_score_idx=0;

  for (auto &[name,scores]:name_and_score) {
    int64_t final_score=0;
    for(auto &[_,score]:scores) {
      final_score+=score;
    }
    if(final_score<max_score) {
      continue;
    }
    int64_t part_score=0;
    size_t idx=0;
    for(auto &[i,score]:scores) {
      part_score+=score;
      if(part_score>=final_score) {
        idx=i;
        break;
      }
    }
    if(final_score>max_score || idx<max_score_idx) {
      max_score=final_score;
      max_score_idx=idx;
      max_score_name=name;
    }
  }


  std::cout<<max_score_name;

  return 0;
}
