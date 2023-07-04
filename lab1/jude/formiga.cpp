#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

bool compareLength(std::string a, std::string b) {
  if (a.length()!=b.length()){
    return a.length() < b.length();
  }
  else{
    return a < b;
  }
}

int main() {
    std::string frase;
    std::getline(std::cin, frase);
    std::stringstream iss(frase);
    std::vector<std::string> palavras;
    std::string word;

    while (iss >> word) {
        palavras.push_back(word);
    }

    std::sort(palavras.begin(), palavras.end(), compareLength);

    for (const auto& substring : palavras) {
        std::cout << substring << ' ';
    }

    return 0;
}

