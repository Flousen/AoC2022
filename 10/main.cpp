#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

enum Op { noop, addx };
typedef std::tuple<Op,int> Cmd;

void check(int tick, int reg, int &sol){
  if (
    (tick == 20 ) || (tick == 60 ) || (tick == 100) ||
    (tick == 140) || (tick == 180) || (tick == 220)
  ) {
    sol += tick*reg;
  }
}

void check2(int & tick, int & reg, std::vector<std::string> & display){
  std::string pix = tick>=reg-1 && tick<=reg+1 ? "#" : " ";
  display.back().append(pix);
  tick++;
  if (tick==40){
    tick=0;
    display.push_back(std::string());
  }
}

void print(std::vector<std::string> disp){
  for (auto & line:disp){
    std::cout << line << std::endl;
  }
}

int main() {
  // read data
  std::vector<Cmd> data;
  Op op;
  int val=0;
  for(std::string line; std::getline(std::cin, line);) {
    op = line.substr(0,4) == "noop" ? noop : addx;
    if (op == addx)
      val = std::stoi( line.substr(5) );
    data.push_back(std::make_tuple(op,val));
  }

  // first star
  int tick=0, reg=1, sol=0;
  for (auto & el: data){
    check(++tick, reg, sol);
    if (std::get<0>(el)== addx){
      check(++tick, reg, sol);
      reg += std::get<1>(el);
    }
  }
  std::cout << sol << std::endl;

  // second star
  tick=0, reg=1;
  std::vector<std::string> display;
  display.push_back(std::string());
  for (auto & el: data){
    check2(tick, reg, display);
    if (std::get<0>(el) == addx){
      check2(tick, reg, display);
      reg += std::get<1>(el);
    }
  }
  print(display);

  return EXIT_SUCCESS;
}