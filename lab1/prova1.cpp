#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void cinema(){
    int n, p;
    std::cin>>n;
    std::cin>>p;
    std::vector<int> todos;
    std::vector<int> ocupados;
    std::string nums = "";
    for (int i = 1; i<n+1; i++){
        todos.push_back(i);
    }
    if (p != 0){
        std::cin.ignore();
        std::getline(std::cin, nums);
        std::istringstream iss(nums); 
        int num;
        while (iss >> num) {
            ocupados.push_back(num);
            }
        sort(ocupados.begin(),ocupados.end());
        for (int i: ocupados){
            auto it = std::find(todos.begin(), todos.end(), i);
            if (it != todos.end()) {
                todos.erase(it);
            }
        }
    }
    for (int i=0;i<todos.size();i++){
        std::cout<<todos[i];
        if (i<todos.size()-1){
            std::cout<<" ";
        }
    }
}

void elo(){
    int total,n1,n2,n3,n4,n5,n6;
    std::cin>>n1>>n2>>n3>>n4>>n5>>n6;
    total = n1 + n2 + n3 +n4 +n5 +n6;
    if (total<40){
        std::cout<<"B-";
    }
    else if (total<60){
        std::cout<<"B";
    }
    else if (total<80){
        std::cout<<"B+";
    }
    else if (total<100){
        std::cout<<"A-";
    }
    else if (total<150){
        std::cout<<"A";
    }
    else if (total<180){
        std::cout<<"A+";
    }
    else if (total<200){
        std::cout<<"S-";
    }
    else if (total<250){
        std::cout<<"S";
    }
    else if (total>249){
        std::cout<<"S+";
    }
}

void op(){
    int x,y;
    std::cin>>x>>y;
    if (((x>100)||(x<0))||((y>100)||(y<0))){
        std::cout<<"Coordenada invalida";
    }
    else if ((x>70)||(y>70)){
        std::cout<<"Coordenada valida e o navio esta longe";
    }
    else{
        std::cout<<"Coordenada valida e o navio esta perto";
    }
}

void bola(){
    unsigned long long int q;
    int n;
    unsigned long long int total;
    std::cin>>n>>q;
    total = 0;
    for (int i = 0; i<n;i++){
        total = total + q;
        q = q + q;
    }
    std::cout<<total;
}

int main(){
    bola();
}