#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <tuple>
#include <set>
#include <cmath>

typedef std::tuple<int,int> Pos;

std::map<char, Pos > dir{
  {'R', std::make_tuple(0,1)},
  {'L', std::make_tuple(0,-1)},
  {'U', std::make_tuple(1,0)},
  {'D', std::make_tuple(-1,0)},
};

bool check_dist(Pos H, Pos T){
  if ( 
    (std::abs (std::get<0>(H) - std::get<0>(T))>=2)  || 
    (std::abs (std::get<1>(H) - std::get<1>(T))>=2) )
    return true;
  return false;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}

void newtail(Pos H, Pos* T){
  std::get<0>(*T) += sign(std::get<0>(H) - std::get<0>(*T));
  std::get<1>(*T) += sign(std::get<1>(H) - std::get<1>(*T));
}

int main() {
  // read data
  std::vector<std::tuple<char,int>> data;

  for(std::string line; std::getline(std::cin, line);) {
    data.push_back( std::make_tuple(line[0], std::stoi( line.substr(2) ) ) );
  }

  // first star
  Pos T = std::make_tuple(0,0);
  Pos H = std::make_tuple(0,0);
  std::set<Pos> visited;
  visited.insert(std::make_tuple(0,0));
  for (auto & el: data){
    char ldir = std::get<0>(el);
    int dist = std::get<1>(el);
    for (int i = 0; i<dist; i++){
      std::get<0>(H) += std::get<0>(dir[ldir]);
      std::get<1>(H) += std::get<1>(dir[ldir]);
      if ( check_dist(H, T) ) newtail(H,&T);
      visited.insert(T);
    } 
  }
  std::cout <<  visited.size() << std::endl;

  // second star
  int len=10;
  std::vector<Pos> rope;
  for(int i=0; i<len; i++) rope.push_back(std::make_tuple(0,0));
  visited.clear();
  for (auto & el: data){
    char ldir = std::get<0>(el);
    int dist = std::get<1>(el);
    for (int i = 0; i<dist; i++){
      std::get<0>(rope.front()) += std::get<0>(dir[ldir]);
      std::get<1>(rope.front()) += std::get<1>(dir[ldir]);
      for(int j=0; j<len-1; j++)
        if ( check_dist(rope[j], rope[j+1]) ) newtail(rope[j], &rope[j+1]);
      visited.insert(rope.back());
    }
  }
  std::cout <<  visited.size() << std::endl;
  
  return EXIT_SUCCESS;
}