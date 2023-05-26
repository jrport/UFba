#include <string>
#include <iostream>

int main(){
    int n;
    std::cin>>n;
    std::cin.ignore();
    std::string itens, itens_rev;
    getline(std::cin, itens);
    for (int i = itens.size(); i>-1; i--){
        itens_rev = itens_rev + itens[i];
    }
    std::cout<<itens_rev;
    return 0;
}