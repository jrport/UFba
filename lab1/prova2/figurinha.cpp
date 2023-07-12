#include <iostream>
#include <vector>

int bsearch(std::vector<int>& vetor, int valorProcurado) {
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
  int status ,fig_num, req_num, id, quant;
  std::vector<int> fig_posse, quant_fig_posse, req_fig;
  std::cin >> fig_num;
  
  for (int i = 0; i < fig_num; i++){
    std::cin >> id;
    fig_posse.push_back(id);
  }

  
  for (int i = 0; i < fig_num; i++){
    std::cin >> quant;
    quant_fig_posse.push_back(quant);
  }

  std::cin >> req_num;
  for (int i = 0; i < req_num; i++){
    std::cin >> id;
    req_fig.push_back(id);
  }

  int indice;
  for (int i : req_fig){
    indice = bsearch(fig_posse, i);
    if (indice!=-1){
      if (quant_fig_posse[indice]==0){
        std::cout<<"Quero\n";
      }
      else if(quant_fig_posse[indice]==1){
        std::cout<<"Apenas uma\n";
      }
      else{
        std::cout<<"Trocar\n";
      }
    }
    else{
      std::cout<<"Quero\n";
    }
  }
  
  return 0;
}
