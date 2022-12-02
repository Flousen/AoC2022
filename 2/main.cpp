#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

int main() {
  // read data
  std::vector<std::tuple<char, char>> data;

  std::map<char, int> value = {
    {'A', 1},
    {'B', 2},
    {'C', 3}
  };

  std::map<char, char> conv = {
    {'X', 'A'},
    {'Y', 'B'},
    {'Z', 'C'}
  };

  for(std::string line; std::getline(std::cin, line);) {
    data.push_back(std::make_tuple(line[0], line[2]) );
  }
  
  int res = 0;
  for(auto i: data){
    char elf = std::get<0>(i);
    char me  = conv[std::get<1>(i)];
    res += value[me];
    if(elf == me){
      res += 3;
    } else if(
      (elf == 'A' && me == 'B') ||
      (elf == 'B' && me == 'C') ||
      (elf == 'C' && me == 'A') 
    ){
      res += 6;
    }
  }
  std::cout << res << std::endl;

  std::map<char, std::map<char, int>> eval = {
    {'X', {
      {'A', value['C']},
      {'B', value['A']},
      {'C', value['B']}
    }},
    {'Y', {
      {'A', value['A']+3},
      {'B', value['B']+3},
      {'C', value['C']+3}
    }},
    {'Z', {
      {'A', value['B']+6},
      {'B', value['C']+6},
      {'C', value['A']+6}
    }}
  };

  res = 0;
  std::for_each(data.cbegin(), data.cend(), [&](auto i){
    res += eval[std::get<1>(i)][std::get<0>(i)];
  });

  std::cout << res << std::endl;

  return EXIT_SUCCESS;
}