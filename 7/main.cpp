#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <sstream>
#include <functional>
#include <numeric>


int get_size(std::string a){
  int size = 0;
  if (std::isdigit(a[0])){
    std::string buff;
    std::stringstream str(a);
    std::getline(str, buff, ' ');
    size = std::stoi(a);
  }
  return size;
}

int main() {
  // read data
  std::vector<int> sizes;
  std::vector<int> stack;
  for(std::string line; std::getline(std::cin, line);) {
    if (line =="$ cd .."){
      sizes.push_back(stack.back());
      stack.pop_back();
    } else if (line.rfind("$ cd ", 0) == 0){
      stack.push_back(0);
    } else {
      int val = get_size(line);
      std::transform(stack.begin(), stack.end(), 
        stack.begin(),
        std::bind2nd(std::plus<int>(), val)
        );
    }
  }

  sizes.insert( sizes.end(), stack.begin(), stack.end() );
  int res = std::accumulate(
    sizes.begin(), sizes.end(), 0,
    [](int a, int b){return b<=100000 ? a+b : a;}
  ); 

  // first star  
  std::cout << res << std::endl;

  // second star
  std::sort (sizes.begin(), sizes.end());
  int free = sizes.back() - 40000000;
  auto res2 = std::upper_bound(sizes.begin(), sizes.end(), free);

  std::cout << *res2 << std::endl;

  return EXIT_SUCCESS;
}