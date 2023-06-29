#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int a, mul;
  string nums;
  vector<int> vec;
  cin >> a;
  cin.ignore();
  getline(cin,nums);
  int num;
  istringstream iss(nums);
  while (iss>>num){
    vec.push_back(num);
  }
  cin>>mul;
  for (int i:vec){
    printf("%d ",i*mul);
  }
}
