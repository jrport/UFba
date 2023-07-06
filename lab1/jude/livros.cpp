#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> book_name, requests;
    std::vector<int> book_status;
    int book_quant, status;
    
    std::cin >> book_quant;
    std::cin.ignore();

    for (int i = 0; i < book_quant; i++) {
        std::string name;
        std::getline(std::cin, name);
        std::stringstream iss(name);
        iss >> name >> status;
        book_name.push_back(name);
        book_status.push_back(status);
    }

    int req_num;
    std::cin >> req_num;
    std::cin.ignore();
    
    std::string req_name;
    std::getline(std::cin, req_name);
    std::stringstream ss(req_name);
    std::string it;
    
    while (ss >> it) {
        requests.push_back(it);
    }

    for (const std::string& target : requests) {
        auto it = std::find(book_name.begin(), book_name.end(), target);
        if (it == book_name.end()) {
            std::cout << "Nao encontrado\n";
        } else {
            int index = std::distance(book_name.begin(), it);
            if (book_status[index] == 1) {
                std::cout << "Disponivel\n";
            } else {
                std::cout << "Emprestado\n";
            }
        }
    }

    return 0;
}

