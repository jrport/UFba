#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main () {
  int argc;
  std::cin>>argc;
  std::string strin;
  std::cin.ignore();
  std::getline(std::cin,strin); 
  std::vector<int> vec;
  std::istringstream iss(strin);
  int n;
  while (iss>>n){
    vec.push_back(n);
  }
  int par, impar;
  par = 0;
  impar = 0;
  int size = vec.size();
  for (int i = 0; i<size; i++){
    if (i%2 == 0){
      par += vec[i];
    }
    else{
      impar += vec[i];
    }
  }
  if (par>impar){
    printf("Vou ajudar");
  }
  else{
    printf("Modo Hard");
  }
  return 0;
}
