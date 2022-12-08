#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <numeric>
#include <bitset>

std::bitset<26> f(char a){
  std::bitset<26> vec;
  vec[(int)a - 97] = true;
  return vec;
}

bool f(std::initializer_list<char> comp){
  std::bitset<26> vec;
  for( auto el: comp )
    vec |= f(el);
  return vec.count() == comp.size();
}

int main() {
  // read data
  for(std::string line; std::getline(std::cin, line);) {
    // first star
    for (int i = 0; i<line.length(); ++i){
      if (f({line[i], line[i+1], line[i+2],line[i+3]})){
        std::cout <<"*  "<< i+4 << std::endl;
        break;
      }
    }
    // second star
    for (int i = 0; i<line.length(); ++i){
      if (f({line[i], line[i+1], line[i+2],line[i+3],line[i+4],line[i+5],line[i+6],line[i+7],line[i+8],line[i+9],line[i+10],line[i+11],line[i+12],line[i+13]})){
        std::cout <<"** "<< i+14 << std::endl;
        break;
      }
    }
  }
  

  return EXIT_SUCCESS;
}