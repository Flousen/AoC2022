#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <numeric>

std::vector<bool> f(char a){
  std::vector<bool> vec(26);
  vec[(int)a - 97] = true;
  return vec;
}

bool f(std::initializer_list<char> comp){
  std::vector<bool> vec(26, false);
  int sum=0,l=0;
  for( auto el: comp ){
    std::transform( vec.begin(), vec.end(), f(el).begin(), vec.begin(), std::logical_or<>() );
    l++;
  }
  std::for_each(vec.begin(), vec.end(), [&sum](bool a){if(a) sum++;});
  return sum == l;
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