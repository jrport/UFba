#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
  int range, num, mul;
  string nums;
  vector<int> points, indexes;
  cin>>range;
  cin.ignore();
  getline(cin,nums);
  istringstream iss(nums);
  while (iss>>num){
    points.push_back(num);
  }
  mul = range / 2;
  cout<<mul;
  return 0;
}
