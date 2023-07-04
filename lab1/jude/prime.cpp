#include <iostream>
#include <vector>

int main () {
  std::vector<int> vec;
  int i = 1;
  int check = 0;
  while (i!=0){
    std::cin>>i;
    if (i==0){
      break;
    }
    vec.push_back(i);
  }
  for (i = 0; i<vec.size();i++){
    if (vec[i] == 1){
      printf("O numero de cadeiras nao eh primo!\n");
    }
    else if (vec[i]==0){
      break;
    }
    else if (vec[i]==2){
      printf("O numero de cadeiras eh primo!\n");
    }
    else{
      for (int j = 2; j<vec[i]; j++){
        if (vec[i]%j==0){
          check = 1;
        }
      }
      if (check == 1){
        printf("O numero de cadeiras nao eh primo!\n");
        check = 0;
      }
      else {
        printf("O numero de cadeiras eh primo!\n");
      }
    }
  }
  return 0;
}
