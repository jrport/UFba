#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
int main () {
  int block_count, max_height, height, points;
  points = 0;
  std::string block;
  
  std::cin>>block_count>>max_height;
  std::cin.ignore();

  std::vector<std::bitset<3>> blocks;

  for (int i = 0; i < block_count; i++){
    std::getline(std::cin,block);
    std::bitset<3> bitblock(block);
    blocks.push_back(bitblock);
  }

  std::vector<std::bitset<3>> blocks_complement;

  for (std::bitset<3> complement:blocks){
    blocks_complement.push_back(~(complement));
  }
  // std::cout<<"Complements: \n";
  // for (std::bitset<3> bits:blocks_complement){
  //   std::cout<<bits<<'\n';
  // }
  for (std::bitset<3> bits:blocks_complement){
    auto item = std::find(blocks.begin(),blocks.end(),bits);
    if (item!=blocks.end()){
      block_count -= 2;
      points += 5;
    }
  }
  if (block_count<max_height){
    printf("%d",points);
  } 
  else{
    printf("game over");
  }
  
  return 0;
}
