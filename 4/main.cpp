#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <regex>
#include <iterator>

int main() {
  // read data
  std::vector<std::vector<int>> data;
  for(std::string line; std::getline(std::cin, line);) {
    std::regex words_regex("(\\d+)");
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
    auto words_end = std::sregex_iterator();
    data.push_back(std::vector<int>());
    for (std::sregex_iterator i = words_begin; i != words_end; ++i){
      data.back().push_back(std::stoi(i->str())) ; 
    }
  }

  // first star
  int sum=0;
  std::for_each(data.cbegin(), data.cend(), [&sum](auto i){
    if ((i[0] <= i[2] && i[3] <= i[1]) || (i[2] <= i[0] && i[1] <= i[3]) ) sum++;
  });
  std::cout << sum << std::endl;

  // second star
  sum=0;
  std::for_each(data.cbegin(), data.cend(), [&sum](auto i){
    if (i[0] <= i[3] && i[2] <= i[1]) sum++;
  });
  std::cout << sum << std::endl;

  return EXIT_SUCCESS;
}