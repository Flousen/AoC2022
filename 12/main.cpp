#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>


typedef std::pair<int, int> pt;
typedef std::vector<std::vector<int>> grid;

std::tuple<grid, pt, pt> parse(){
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
  return {g, strt, ende};
}

void print (grid g){
  for (auto & row: g){
    for (auto & col: row) std::cout << col << " ";
    std::cout << std::endl;
  }
}

int main() {
  // read data
  auto [g, strt, ende] = parse();
  print(g);
  // first star
  //std::cout << shortest_path(g, strt, ende) << std::endl;

  // second star

  return EXIT_SUCCESS;
}