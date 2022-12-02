#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main() {
  // read data
  std::vector<int> data{0};
  for (std::string line; std::getline(std::cin, line);) {
    if (line == "") data.push_back(0);
    else data.back() += std::stoi(line);
  }

  // first star - top tier eater
  std::cout << *std::max_element(data.begin(), data.end()) << std::endl;
  // second star - top 3 eater
  std::sort (data.begin(), data.end());
  std::cout << std::reduce(data.end()-3, data.end() ) << std::endl;

  return EXIT_SUCCESS;
}