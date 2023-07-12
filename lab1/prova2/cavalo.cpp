#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int buscaBinaria(std::vector<int>& vetor, int valorProcurado) {
  int esquerda = 0;
  int direita = vetor.size() - 1;
  while (esquerda <= direita) {
    int meio = esquerda + (direita - esquerda) / 2;
    if (vetor[meio] == valorProcurado) {
      return meio;
    }
    if (vetor[meio] < valorProcurado) {
    esquerda = meio + 1;
    } else {
    direita = meio - 1;
    }
  }
  return -1;
}

int main () {
  int num_corridas;
  std::cin>>num_corridas;
  std::vector<int> indices;
  for (int i = 0; i<num_corridas; i++){
    int num_cavalos, cavalo;
    std::cin>>num_cavalos;
    std::vector <int> cav_nums;
    std::string cavalos;
    std::cin.ignore();
    std::getline(std::cin,cavalos);
    std::stringstream iss(cavalos);
    while (iss>>cavalo){
      cav_nums.push_back(cavalo);
    }
    int alvo;
    std::cin>>alvo;
    indices.push_back(buscaBinaria(cav_nums,alvo));
  }
  for (int i: indices){
      std::cout<<i<<std::endl;
    }
  return 0;
}
