#include <iostream>

void op(){
    int x,y;
    std::cin>>x>>y;
    if(((x>0)&(x<100))&((y>0)&(y<100))){
        if((x>70)||(y>70)){
            std::cout<<"Coordenada valida e o navio esta longe";
        }
        else{
            std::cout<<"Coordenada valida e o navio esta perto";
        }
    }   
    else{
        std::cout<<"Coordenada invalida";
    }
}

int main(){
    op();
}