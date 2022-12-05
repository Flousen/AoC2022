#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <regex>
#include <iterator>
#include <list>

int main() {
  // read data
  std::vector<std::list<char>> stacks;

  for(std::string line; std::getline(std::cin, line);) {
    if (stacks.size() == 0) 
      for (int i = 0; i <=(line.length()+1)/4; i++) 
        stacks.push_back(std::list<char>{});
    if (line[1] == '1') break;
    for (int i = 1, j = 0; i<= line.length(); i+=4, j++)
      if(line[i] != ' ') 
        stacks[j].push_front(line[i]);
  }

  std::vector<std::list<char>> stacks2 = stacks;

  std::string line; std::getline(std::cin, line); // pop emptz line
  std::vector<std::tuple<int,int,int>> instructions;
  for(std::string line; std::getline(std::cin, line);) {
    std::regex words_regex("(\\d+)");
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    auto words_end = std::sregex_iterator();
    std::sregex_iterator i = words_begin;
    int a = std::stoi( i++->str());
    int b = std::stoi( i++->str())-1;
    int c = std::stoi( i->str())-1;
    instructions.push_back( std::make_tuple( a, b, c)) ; 
  }

  // first star
  for (auto const & i: instructions){
    for (int n = 0; n < std::get<0>(i); n++){
      stacks[std::get<2>(i)].push_back( stacks[std::get<1>(i)].back() );
      stacks[std::get<1>(i)].pop_back();
    }
  }

  for (auto const & i: stacks) std::cout << i.back();
  std::cout << std::endl;
  // second star
  for (auto const & i: instructions){
    int n = std::get<0>(i);
    std::list<char>& a = stacks2[std::get<1>(i)];
    std::list<char>& b = stacks2[std::get<2>(i)];
    b.insert( b.end(), std::prev(a.end(), n), a.end());
    for (int j = 0; j < n; j++)
      a.pop_back();
  }
  for (auto const & i: stacks2) std::cout << i.back();
  std::cout << std::endl;

  return EXIT_SUCCESS;
}