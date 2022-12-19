#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <regex>
#include <iterator>
#include <set>
#include <stdlib.h> 

typedef std::pair<int, int> pt;
                                                  
template <typename T,typename U>
std::pair<T,U> operator+(const std::pair<T,U> & l, const std::pair<T,U> & r) {
  return {l.first+r.first,l.second+r.second};
}

template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l, const std::pair<T,U> & r) {
  return {l.first-r.first,l.second-r.second};
}

template <typename T,typename U>
std::ostream& operator<<(std::ostream& os, std::pair<T,U> const& a) {
  os << '(' << a.first << ',' << a.second << ')';
  return os;
}

template <typename T,typename U>
bool operator<=( std::pair<T,U>& lhs,std::pair<T,U>& rhs ){
  return lhs.first <= rhs.first && lhs.second <= rhs.second;
}

int distance(pt a, pt b){
  pt c = a-b;
  return abs(c.first) + abs(c.second);
}

bool is_covered(std::vector<std::tuple<pt, pt, int>> data, pt a){
  for (auto & el: data){ 
    if (distance(a, std::get<0>(el)) <= std::get<2>(el) ){
      return true;
    };
  }
  return false;
}
int gx;

bool check_line(std::vector<std::tuple<pt, pt, int>> data, int y){
  std::vector<pt> ranges;
  
  for (auto & el: data){
    int diff = abs(std::get<0>(el).second - y);
    if ( diff <= std::get<2>(el)){
      int len = std::get<2>(el) - diff;
      int start = (std::get<0>(el).first - len);
      start = start <0 ? 0: start;
      int end = start + (len*2)+1;
      insert_range(ranges, {start, end});
    }
  }

  if (el != line.end() ){
    gx = std::distance(line.begin(),el);
    return true;
  } else {
    return false;
  }
  
}

int main() {
  // read data
  std::vector<std::tuple<pt, pt, int>> data;

  std::set<int> set;
  std::set<pt> bacon;
  std::vector<int> dist;

  for(std::string line; std::getline(std::cin, line);) {
    std::regex words_regex("(-?\\d+)");
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    auto words_end = std::sregex_iterator();
    std::sregex_iterator i = words_begin; 
    int first = std::stoi(i->str()); ++i;
    int second = std::stoi(i->str()); ++i;
    int third = std::stoi(i->str()); ++i;
    int fourth = std::stoi(i->str());
    data.push_back({{first,second},{third,fourth}, distance({first,second},{third,fourth})});
  }
  // first star
  for (auto & el: data){
    set.insert(std::get<0>(el).first);
    bacon.insert(std::get<1>(el));
    dist.push_back(std::get<2>(el));
  }
  int min = *set.begin() - *std::max_element(dist.begin(), dist.end());
  int max = *set.rbegin() + *std::max_element(dist.begin(), dist.end());

  //int y=10;
  //int y=2000000;
  //int num=0;
  //for (int x = min; x<=max; x++){
  //  if (bacon.contains({x,y})) continue;
  //  for (auto & el: data){ 
  //    if (distance({x,y}, std::get<0>(el)) <= std::get<2>(el) ){
  //      num++;
  //      break;
  //    };
  //  }
  //}
  //std::cout << "num " << num << std::endl;

  // second star
  pt erg;
  for (int y = 0; y <= 4000000; y++){
    if (check_line(data, y)){
      erg = {gx,y};
      break;
    }
  }
  std::cout << "erg " << erg << std::endl;

  return EXIT_SUCCESS;
}