#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <numeric>


int eval(char a){
  int b = (int)a;
  if ( (unsigned)(b-96) <= (122-96) ) return b - 96;
  return b-63+25;
}

int main() {
  // read data
  std::vector<std::tuple<std::string, std::string>> data;

  for(std::string line; std::getline(std::cin, line);) {
    int n = line.length();
    data.push_back(std::make_tuple(line.substr(0,n/2), line.substr(n/2,n)));
  }

  // first star
  int sum =0;
  std::for_each(data.cbegin(), data.cend(), [&](auto i){
    int a =  std::get<0>(i).find_first_of(std::get<1>(i));
    sum += eval(std::get<0>(i)[a]);
  });
  std::cout << sum << std::endl;

  // second star
  std::vector<std::string> dat;
  std::for_each(data.cbegin(), data.cend(), [&](auto i){
    dat.push_back(std::get<0>(i)+std::get<1>(i));
  });

  sum = 0;
  for(std::vector<std::string>::iterator it = dat.begin(); it != dat.end(); it+=3) {
    std::string final;
    final = std::reduce(it+1, it+3, *it,
      [](std::string a, std::string b){
        std::string s_intersection;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::set_intersection(a.begin(), a.end(),
                              b.begin(), b.end(),
                              std::back_inserter(s_intersection));
        return s_intersection;
      }
    );
    sum += eval(final[0]);
  }
  std::cout << sum<< std::endl;
  return EXIT_SUCCESS;
}