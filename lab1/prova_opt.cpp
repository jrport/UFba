#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int r, c;
  string nums = "";
  cin >> r >> c;
  int array[50][50];

  cin.ignore();
  cout << "Matrix A:" << endl;
  for (int i = 0; i < r; i++) {
    int j = 0;
    getline(cin, nums);
    int num;
    istringstream iss(nums);
    while (iss >> num) {
      array[i][j] = num;
      j++;
    }
    nums = "";
  }

  int array1[50][50];
  cout << "Matrix B:" << endl;
  for (int i = 0; i < r; i++) {
    int j = 0;
    getline(cin, nums);
    int num;
    istringstream iss(nums);
    while (iss >> num) {
      array1[i][j] = num;
      j++;
    }
    nums = "";
  }

  cout << "Matrix C:" << endl;
  int array2[50][50];
  for (int i = 0; i < r; i++) {
    for (int x = 0; x < c; x++) {
      array2[i][x] = array[i][x] + array1[i][x];
      cout << array2[i][x] << " ";
    }
    cout << endl;
  }
}
