/*!
 * \file 3C.cpp
 *
 * \brief http://codeforces.com/problemset/problem/3/C
 * \author cyy
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

int cross_cnt=0;
int nought_cnt=0;
int line_weights[8]{};

bool has_valid_intersection(int weight) {
  std::set<std::pair<size_t,size_t>> intersection_point;
  for(size_t i=0;i<3;i++) {
    if(line_weights[i]!=weight) {
      continue;
    }
    for(size_t j=3;j<6;j++) {
      if(line_weights[j]!=weight) {
        continue;
      }
      intersection_point.emplace(i,j);
      if(intersection_point.size()>1) {
        return false;
      }
    }
    if(line_weights[6]==weight) {
      intersection_point.emplace(i,i);
      if(intersection_point.size()>1) {
        return false;
      }
    }
    if(line_weights[7]==weight) {
      intersection_point.emplace(i,2-i);
      if(intersection_point.size()>1) {
        return false;
      }
    }
  }

  for(size_t j=3;j<6;j++) {
    if(line_weights[j]!=weight) {
      continue;
    }

    if(line_weights[6]==weight) {
      intersection_point.emplace(j,j);
      if(intersection_point.size()>1) {
        return false;
      }
    }
    if(line_weights[7]==weight) {
      intersection_point.emplace(2-j,j);
      if(intersection_point.size()>1) {
        return false;
      }
    }
  }
    if(line_weights[6]==weight && line_weights[7]==weight) {
      intersection_point.emplace(1,1);
    }
  return intersection_point.size()==1;
}

int main(void) {


  for (size_t i=0;i<3;i++) {
    for (size_t j=0;j<3;j++) {
      char c;
      std::cin>>c;
      if(c=='X') {
        line_weights[i]++;
        line_weights[3+j]++;
        if(i==j) {
          line_weights[6]++;
        } 
        if (i+j==2) {
          line_weights[7]++;
        }
        cross_cnt++;
      } else if(c=='0') {
        line_weights[i]--;
        line_weights[3+j]--;
        if(i==j) {
          line_weights[6]--;
        } 
        if (i+j==2) {
          line_weights[7]--;
        }
        nought_cnt++;
      }
    }
  }

  size_t first_won=0;
  size_t second_won=0;
  for(auto &weight:line_weights) {
    if(weight==3) {
      first_won++;
    } else if(weight==-3) {
      second_won++;
    }
  }

  if(cross_cnt!=nought_cnt&& cross_cnt !=nought_cnt+1) {
    std::cout<<"illegal"<<std::endl;
    return 0;
  }

  if(first_won&&second_won) {
    std::cout<<"illegal"<<std::endl;
    return 0;
  }
  if(first_won) {
    if(first_won>1) {
      if(!has_valid_intersection(3)) {
        std::cout<<"illegal"<<std::endl;
        return 0;
      }
    }
    if(nought_cnt==cross_cnt) {
      std::cout<<"illegal"<<std::endl;
    } else {
      std::cout<<"the first player won"<<std::endl;
    }
    return 0;
  }

  if(second_won) {
    if(second_won>1) {
      if(!has_valid_intersection(-3)) {
        std::cout<<"illegal"<<std::endl;
        return 0;
      }
    }
    if(cross_cnt>nought_cnt) {
      std::cout<<"illegal"<<std::endl;
    }else {
      std::cout<<"the second player won"<<std::endl;
    }
    return 0;
  }

  if(cross_cnt+nought_cnt==9) {
    std::cout<<"draw"<<std::endl;
    return 0;
  }

  if(cross_cnt==nought_cnt) {
    std::cout<<"first"<<std::endl;
  } else {
    std::cout<<"second"<<std::endl;
  }
  return 0;
}
