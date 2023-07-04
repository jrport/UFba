#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main () {
  int fases, num, vida_max, vida_atual;
  std::string strin;
  std::cin>>fases;
  std::cin.ignore();
  std::getline(std::cin,strin);
  std::istringstream iss(strin);
  std::vector<int> vec;
  std::cin>>vida_max;
  vida_atual = vida_max;
  while (iss>>num){
    vec.push_back(num);    
  }
  for (int i : vec){
    if (i==1){;
      vida_atual = vida_max;
    }
    else if (i>1){
      vida_atual -= i;
    }
    if (vida_atual<=0){
      printf("You Died");
      return 0;
    }
  }
  printf("Yes, you can");
  return 0;
}
