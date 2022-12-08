#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

int is_vis(std::vector<std::vector<int>> forest, int i, int j){
  int h = forest[i][j];
  bool vis = true;
  for (int k=j+1; k < forest[i].size(); k++)
    if (forest[i][k]>= h){
      vis = false;
      break;
    }
  if (vis) return 1; vis = true;
  for (int k=j-1; k >= 0 ; k--)
    if (forest[i][k]>= h){
      vis = false;
      break;
    }
  if (vis) return 1; vis = true;
  for (int k=i+1; k < forest.size(); k++)
    if (forest[k][j]>= h){
      vis = false;
      break;
    }
  if (vis) return 1; vis = true;
  for (int k=i-1; k >= 0; k--)
    if (forest[k][j]>= h){
      vis = false;
      break;
    }
  if (vis) return 1; vis = true;
  return 0;
}


int treesocre(std::vector<std::vector<int>> forest, int i, int j){
  int h = forest[i][j];
  int score = 1;
  int s=0;
  for (int k=j+1; k < forest[i].size(); k++){
    s++;
    if (forest[i][k]>= h){
      break;
    }
  }
  score*=s; s=0;
  for (int k=j-1; k >= 0 ; k--){
    s++;
    if (forest[i][k]>= h){
      break;
    }
  }
  score*=s; s=0;
  for (int k=i+1; k < forest.size(); k++){
    s++;
    if (forest[k][j]>= h){
      break;
    }
  }
  score*=s; s=0;
  for (int k=i-1; k >= 0; k--){
    s++;
    if (forest[k][j]>= h){
      break;
    }
  }
  score*=s;
  return score;
}

int main() {
  // read data
  std::vector<std::vector<int>> forest;
  for(std::string line; std::getline(std::cin, line);) {
    forest.push_back(std::vector<int>());
    for (char &c: line){
      forest.back().push_back((int)c - 48);
    }
    
  }

  // first star
  int m = forest.size();
  int n = forest.front().size();
  int sum=2*(m-1) + 2* (n-1);
  for(int i=1; i<m-1; i++){
    for(int j=1; j<n-1; j++){
      sum+= is_vis(forest, i,j);
    }
  }
  std::cout << sum << std::endl;
  
  // second star
  std::vector<int> score;
  for(int i=1; i<m-1; i++){
    for(int j=1; j<n-1; j++){
      score.push_back(treesocre(forest, i,j));
    }
  }
  std::cout << *std::max_element(score.begin(), score.end()) << std::endl;
  
  return EXIT_SUCCESS;
}