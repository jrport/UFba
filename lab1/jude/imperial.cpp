#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main () {
  int util_num;
  float num;
  std::vector<float> total, acertos;
  std::cin>>util_num;
  std::string strin;
  std::cin.ignore();
  std::getline(std::cin,strin);
  std::stringstream iss(strin);
  while (iss>>num){
    total.push_back(num);
  }
  std::getline(std::cin,strin);
  std::stringstream iss2(strin);
  while (iss2>>num){
    acertos.push_back(num);
  }
  for (int i = 0; i<util_num; i++){
    printf("%.0f", (std::floor((acertos[i]/total[i])*100)));
    if (i!=util_num-1){
      printf(" ");
    }
  }
  return 0;
}
