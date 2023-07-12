#include <iostream>
#include <vector>
int main () {
  int fileiras, cadeiras;
  std::cin >> fileiras;
  std::cin >> cadeiras;
  std::vector<std::vector<int>> assentos(fileiras, std::vector<int>(cadeiras));

  for (int i = 0; i<fileiras; i++) {
    for (int j = 0; j<cadeiras; j++){
      std::cin >> assentos[i][j];
    }
  }

  int assento1 = -1, assento2 = -1, fileira = -1;
  for (int i = 0; i < fileiras; i++) {
      for (int j = 0; j < cadeiras - 1; j++) {
        if (assentos[i][j] == 0 && assentos[i][j + 1] == 0) {
          assento1 = j;
          assento2 = j + 1;
          fileira = i;
          break;
        }
      }
      if (assento1 != -1) {
        break;
      }
    }

  std::cout << "Fileira: " << fileira + 1 << "\nAssentos: " << assento1 + 1<< " e " << assento2 + 1<< std::endl;

  return 0;
  return 0;
}
