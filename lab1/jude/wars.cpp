#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main () {
  int n, xp, num;
  std::cin >> n >> xp;
  xp = xp*n;
  std::vector<std::string> names;
  std::vector<int> vec;
  std::string strin;
  std::cin.ignore();
  std::getline(std::cin,strin);
  std::istringstream iss(strin);
  while (iss>>num){
    vec.push_back(num);
  }
  names = { "Yoda", "Luke","Ahsoka" };
  for (int i = 0; i<3; i++){
    std::cout<<names[i]<<' '<<vec[i]+xp<<std::endl;
  }
  return 0;
} 
