#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <deque>
#include <set>


typedef std::pair<int, int> pt;
typedef std::vector<std::vector<int>> grid;
                                                  
pt operator+(const pt & l,const pt & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

std::vector<pt> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool is_inside ( grid& g, pt a) {
  if (a.first >= 0 && 
      a.first < g.size() && 
      a.second >= 0 &&
      a.second < g[0].size())
    return true;
  return false;

}

int shortest_path (grid g, pt s, pt e){
  std::deque<std::pair<pt,int>> active;
  std::set<pt> visited;
  int height;
  pt nbr;

  active.push_front({s,0});
  visited.insert(s);


  while (!active.empty()){
    auto [cur, dst] = active.front();

    active.pop_front();
    height = g[cur.first][cur.second];

    for (auto & dir: dirs){
      nbr = cur + dir;
      if ( !is_inside(g, nbr) || 
           g[nbr.first][nbr.second] - height > 1 ) 
        continue;
      if (nbr == e) return ++dst;
      if (visited.contains(nbr)) continue;
      visited.insert(nbr);
      active.push_back({nbr, dst+1});
    }

  }
  return 0;
}

void print (grid g){
  for (auto & row: g){
    for (auto & col: row) std::cout << col << " ";
    std::cout << std::endl;
  }
}

int main() {
  // read data
  grid g;
  pt strt, ende;
  std::string::iterator it;
  std::string line;
  int row, col;
  for(row=0; std::getline(std::cin, line); row++) {
    g.emplace_back();
    for (it = line.begin(), col=0; it != line.end();it++, col++) {
      if (*it == 'S') {
        strt = {row, col};
        g.back().push_back(0);
      } else if (*it == 'E') {
        ende = {row, col};
        g.back().push_back('z' - 'a');
      } else {
        g.back().push_back(*it - 'a');
      }
    }
  }
  //print(g);
  // first star
  std::cout << shortest_path(g, strt, ende) << std::endl;

  // second star
  std::vector<int> pl;
  int start=0;
  for (auto tmp: g){
    pl.push_back(shortest_path(g, {start++,0}, ende));
  }
  std::cout << *std::min_element(std::begin(pl), std::end(pl)) << std::endl;


  return EXIT_SUCCESS;
}