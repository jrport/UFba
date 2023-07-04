#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int main () {
  int block_count, max_height;
  std::string block;

  std::cin >> block_count >> max_height;
  std::cin.ignore(); // Consume the newline character

  std::vector<std::bitset<3>> blocks;
  for (int i = 0; i < block_count ; i++) {
    std::getline(std::cin, block);

    std::bitset<3> bitblock(block);
    blocks.push_back(bitblock); 
  }

  for (int i = 0; i < block_count; i++) {
    std::cout << blocks[i] << std::endl;
  }

  return 0;
}
