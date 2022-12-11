#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <regex>
#include <iterator>

struct Monkey {
    std::deque<uint64_t> items;
    char op;
    uint64_t opval, tru, fals, test;
    int count = 0 ;
};

uint64_t comdiv =1;

void print(Monkey a){
  for (auto & el: a.items) std::cout << el << ", ";
  std::cout << std::endl;
  std::cout << "op " << a.op << ' ' << a.opval << std::endl;
  std::cout << "test " << a.test << std::endl;
  std::cout << "tru "  << a.tru << std::endl;
  std::cout << "fals " << a.fals << std::endl;
  std::cout <<"=================="<< std::endl;
}

void print(std::vector<Monkey>  mkys){
  int c=0;
  for (auto & mky: mkys){
    std::cout << "Monkey " << c++ << ':';
    for (auto & i: mky.items) std::cout <<  i << ' ';
    std::cout << std::endl;
  }
}

void strtolist(std::string line, std::deque<uint64_t>& data){
  std::regex words_regex("(\\d+)");
  auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
  auto words_end = std::sregex_iterator();
  for (std::sregex_iterator i = words_begin; i != words_end; ++i){
    data.push_back(std::stoi(i->str())) ; 
  }
}

int cmp(int item, Monkey mky, int div=1){
  int res;
  switch (mky.op)
  {
  case 'q':
    res = item * item;
    break;
  case '*':
    res = item * mky.opval;
    break;
  case '+':
    res = item + mky.opval;
    break; 
  default:
    break;
  }
  if(div==1) return res % comdiv;
  return res/div;
}


int main() {
  // read data
  std::vector<Monkey> mkys;

  for(std::string line; std::getline(std::cin, line);) {
    if (line.substr(0,6) == "Monkey"){
      mkys.push_back(Monkey());
      mkys.back().count =0;
    } else if (line.substr(0,16) ==  "  Starting items"){
      strtolist(line, mkys.back().items);
    } else if (line.substr(0,23) == "  Operation: new = old "){
      mkys.back().op = line[23];
      if (line.substr(25) == "old") mkys.back().op = 'q';
      else mkys.back().opval = std::stoi(line.substr(25));
    } else if (line.substr(0,21) == "  Test: divisible by "){
      mkys.back().test = std::stoi(line.substr(21));
      comdiv *= mkys.back().test;
    } else if (line.substr(0,29) == "    If true: throw to monkey "){
      mkys.back().tru = std::stoi(line.substr(29));
    }else if (line.substr(0, 30) == "    If false: throw to monkey "){
      mkys.back().fals = std::stoi(line.substr(30));
    }
  }
  
  std::vector<Monkey> org = mkys;
  std::vector<uint64_t> count;
  int rounds;

  // first star
  rounds = 20;
  for (int i=1; i <= rounds; i++){
    for (auto & mky: mkys){
      for (int itm = mky.items.front(); !mky.items.empty();  mky.items.pop_front(), itm = mky.items.front()){
        uint64_t curlvl = cmp(itm,mky,3);
        curlvl%mky.test == 0? mkys[mky.tru].items.push_back(curlvl): mkys[mky.fals].items.push_back(curlvl);
        mky.count++;
      }
    }
  }
  count.clear();
  for (auto & mky: mkys) count.push_back(mky.count);
  std::sort (count.begin(), count.end(), [](int i,int j) { return (i>j); });
  std::cout << count[0]*count[1]<< std::endl; 

  // second star
  mkys = org;
  rounds = 10000;
  for (int i=1; i <= rounds; i++){
    for (auto & mky: mkys){
      for (int itm = mky.items.front(); !mky.items.empty(); mky.items.pop_front(), itm = mky.items.front()){
        uint64_t curlvl = cmp(itm,mky);
        curlvl%mky.test == 0 ? mkys[mky.tru].items.push_back(curlvl) : mkys[mky.fals].items.push_back(curlvl);
        mky.count++;
      }
    }
  }

  count.clear();
  for (auto & mky: mkys) count.push_back(mky.count);
  std::sort (count.begin(), count.end(), [](int i,int j) { return (i>j); });
  std::cout << count[0]*count[1]<< std::endl;

  return EXIT_SUCCESS;
}