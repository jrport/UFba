#include <iostream>
#include <string>
#include <vector>

int bsearch(std::vector<std::string>& vetor, std::string valorProcurado) {
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
  bool check;
  int indice, num_esp, num_req;
  std::string esp, resposta;
  std::vector<std::string> todos_esp;
  std::vector<std::string> req_esp;
  std::vector<std::string> indices;
  std::cin>>num_esp;
  for (int i = 0; i<num_esp; i++){
    std::cin>>esp;
    todos_esp.push_back(esp);
  }
  std::cin>>num_req;
  for (int i = 0; i<num_req; i++){
    std::cin>>esp;
    req_esp.push_back(esp);
  }
  for (std::string nome : req_esp){
    indice = bsearch(todos_esp, nome);
    if (indice==-1){
      std::cout<<nome<<" foi extinto :(\n";
    }
    else{
      std::cout<<nome<<" vive!\n";
    }
  }
  return 0;
}
