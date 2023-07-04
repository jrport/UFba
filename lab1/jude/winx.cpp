#include <iostream>
#include <string>
#include <vector>
void bubble_sort(std::vector<std::string>& nomes) {
    int n = nomes.size();
    bool trocado;
    for (int i = 0; i < n - 1; ++i) {
        trocado = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nomes[j] > nomes[j + 1]) {
                std::swap(nomes[j], nomes[j + 1]);
                trocado = true;
            }
        }
        if (!trocado)
            break;
    }
}

int main () {
  int num_alun; 
  std::vector<std::string> nomes;
  std::cin>>num_alun;
  std::string nome;
  for (int i =0; i<num_alun; i++){
    std::cin>>nome;
    nomes.push_back(nome);
  }
  bubble_sort(nomes);
  for (std::string i: nomes){
    std::cout<<i<<std::endl;
  }
  return 0;
}
