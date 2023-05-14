#include <iostream>
#include <cmath>

void soma2(){
    int a,b;
    std::cin>>a;
    std::cin>>b;
    std::cout<<a+b;
}

void media1(){
    float a, b, c, d, total;
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    std::cin>>d;
    total = ((a+b+c+d)/4);
    if (total>=7.0){
        std::cout<<"Aprovado!";
    }
    else{
        std::cout<<"Reprovado!";
    }
}

void origem(){
    int choice;
    float preco;
    std::cin>>preco>>choice;
    switch (choice)
    {
    case 1:
        std::cout<<"Sul!";
        break;
    case 2:
        std::cout<<"Norte";
        break;
    case 3:
        std::cout<<"Nordeste";
        break;
    case 4:
        std::cout<<"Centro-Oeste";
        break;
    case 5:
        std::cout<<"Sudeste";
        break;
    default:
        std::cout<<"Produto Importado";
        break;
    }
}

void imc(){
    float altura, peso, imc;
    std::cin>>altura,peso;
    imc = (peso/(pow(altura,2)));
    if (imc<18,5){
        std::cout<<"Baixo";
    }
    else if ((imc>=18.5)&&(imc<25.0)){
        std::cout<<"Médio";
    }
    else if ((imc>=25.0)&&(imc<30.0)){
        std::cout<<"Aumentado";
    }
    else if ((imc>=30.0)&&(imc<35.0)){
        std::cout<<"Moderado";
    }
    else if ((imc>=35.0)&&(imc<40.0)){
        std::cout<<"Grave";
    }
    else{
        std::cout<<"Muito Grave";
    }
}

void range(){
    int limit;
    std::cin>>limit;
    for (int i = 1; i<limit; i++){
        std::cout<<i<<" ";
    }
}

void range_dec(){
    int start;
    std::cin>>start;
    for (int i = start; i > 0; i--){
        std::cout<<i<<' ';
    }
}

void media30(){
    float notas [30][4];
    float resultados [30][2];
    for (int i = 0; i<30; i++){
        float media = 0;
        for (int n = 0; n<4; n++){
            std::cin>>notas[i][n];
            media += notas[i][n];
        }
        if ((media/4)>=7.0){
            resultados[i][0] = (media/4);
            resultados[i][1] = (1);
        }
        else {
            resultados[i][0] = (media/4);
            resultados[i][1] = (0);
        }
    }
    for (int i = 0; i<30; i++){
        if (resultados[i][1] == 1){
            printf("Aprovado: %.2f\n",resultados[i][0]);
            }
        else{
            printf("Reprovado %.2f\n",resultados[i][0]);
            }
    }
}



int main (){
    media30();
}