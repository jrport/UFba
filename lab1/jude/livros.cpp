#include <iostream>
#include <iterator>
#include <sstream>
#include <istream>
#include <algorithm>
#include <string>
#include <vector>

bool contains(const std::vector<std::string>& strings, const std::string& target) {
    for (std::string str : strings) {
      std::cout<<str<<std::endl;  
      if (str == target) {
            return true;
        }
    }
    return false;

}int main () {
  std::vector<std::string> book_name, requests;
  std::vector<int> book_status;
  int book_quant, status;
  std::cin>>book_quant;
  std::string name;
  for (int i = 0; i<book_quant; i++){
    std::cin.ignore();
    std::getline(std::cin,name);
    std::stringstream iss(name);
    iss>>name>>status;
    book_name.push_back(name);
    std::cout<<'\n'<<'\n'<<name<<std::endl;
    book_status.push_back(status);
    name = "";
    status = 0;
  }
  std::string req_name;
  int req_num;
  std::cin>>req_num;
  std::cin.ignore();
  std::getline(std::cin,req_name);
  std::istringstream ss(req_name);
  std::string it;
  while (ss>>req_name){
    requests.push_back(req_name);
  }
  for (std::string target:requests){
    std::cout<<'\n'<<target<<std::endl;
    auto it = std::find(book_name.begin(),book_name.end(),target);
    int index = std::distance(book_name.begin(),it);
    std::cout<<index<<std::endl;
    if (!(contains(book_name,target))){
      printf("Nao encontrado\n");
    }
    else{
      if (book_status[index] == 1){
        printf("Disponivel\n");
      }
      else{
        printf("Emprestado\n");
      }
    }
  }
  return 1; 
}
