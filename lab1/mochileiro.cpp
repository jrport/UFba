#include <string>
#include <iostream>
#include <vector>
#include <sstream>

int main(){
  int quant;
  std::string item;
  std::vector<std::string> itens;
  std::string line, output;
  std::cin>>quant;
  std::cin.ignore();
  if (quant == 0){
    return 0;
  }
  std::getline(std::cin,line);
  std::stringstream ss(line);
  while (ss>>item){
    itens.push_back(item);
  }
  for (auto it = itens.rbegin(); it != itens.rend(); ++it) {
    output = *it + " " + output;
  }
  output.pop_back();
  std::cout<<output;
  return 0;
}
