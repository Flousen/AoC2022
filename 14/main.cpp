#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <regex>
#include <iterator>
#include <set>

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

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<T>> const& a) {
  for (int i = 0; i < a.size() ; i++) {
    for (int j = 0; j < a.back().size(); j++) {
      os << a[j][i];
    }
    os << std::endl;
  }
  return os << "==================================" << std::endl;
}

template <typename T,typename U>
std::pair<T,U> sign(std::pair<T,U> x) {
    x.first = (x.first > 0) - (x.first < 0);
    x.second = (x.second > 0) - (x.second < 0);
    return x;
}

void set (std::vector<std::vector<char>>& cave, pt from, pt to){
  pt inc= sign(to - from);
  for (pt i = from; i != to+inc; i=i+inc){
    cave[i.first][i.second] = '#';
  }
}

void build_cave(std::vector<std::vector<char>>& cave, std::vector<std::vector<pt>> data, pt source){
  for (auto & el: data){
    for(std::vector<pt>::iterator it = el.begin(); it != el.end()-1; ++it) {
      set(cave, *it, *(it+1));
    }
  }
}

bool in_bound(std::vector<std::vector<char>>& cave, pt point){
    
  return point.first => 0 && point.first < cave.size();
}

bool insert(std::vector<std::vector<char>>& cave, pt start){
  pt inc = {0,-1};
  pt test = start + inc;

  auto found = std::find(cave.begin()+test.first, cave.end(), '#');

  int y= std::distance(cave.begin(), found);

  

  return true;
}


int main() {
  // read data
  pt source = {500,0};
  std::vector<std::vector<pt>> data;
  std::set<int> firs, sec;

  for(std::string line; std::getline(std::cin, line);) {
    data.emplace_back();
    std::regex words_regex("(\\d+)");
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i){
      int first = std::stoi(i->str()); ++i;
      int second = std::stoi(i->str());
      firs.insert(first);
      sec.insert(second);
      data.back().push_back({first, second}) ; 
    }
  }
  source.first -= *firs.begin();
  for (auto & el: data) for (auto & point: el) point.first -= (*firs.begin());
  // first star
  std::vector<std::vector<char>> cave( (*firs.rbegin() - *firs.begin())+1, std::vector<char>((*sec.rbegin())+1, '.'));
  build_cave(cave, data, source);
  cave[source.first][source.second] = '+';
  std::cout << cave;

  int sol=0;
  while (insert(cave,source)) sol++;

  // second star

  return EXIT_SUCCESS;
}