#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <stack>
#include <string>

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

int area(){
    float ar, bma, bme, alt;
    std::cin>>bma;
    std::cin>>bme;
    std::cin>>alt;
    ar = (((bma+bme)*alt)/2);
    printf("A=%.1f",ar);    
    return 0;
}

void zerinho(){
    int alvo, a,b,c,zero,um;
    std::cin>>a>>b>>c;
    um = 0;
    zero = 0;
    int nums[3];
    nums[0]=a;
    nums[1]=b;
    nums[2]=c;
    for (int i:nums){
        if (i==1){um += 1;}
        else{zero += 1;}
    }
    if ((um != 3)&(zero !=3)){
        if (um>zero){
            alvo = 0;
            }
        else {alvo = 1;}
        for (int i = 0; i<3; i++){
            if (nums[i]==alvo){
                if (i==0){std::cout<<'A';}
                else if (i==1){std::cout<<'B';}
                else{std::cout<<'C';}
            }
        }
    }
    else{std::cout<<"Empate";}
}

int acel(){
    int a, b, c;
    std::cin>>a>>b;
    c = a/b;
    std::cout<<c;
    return 0;
}

void nav(){
    int t, a, b, c, d, e;
    std::cin>>a>>b>>c>>d>>e;
    t = a - (b+c+d+e);
    std::cout<<t;
}

void mochila(){
    int n;
    std::cin>>n;
    std::cin.ignore();
    std::string itens, itens_rev;
    getline(std::cin, itens);
    for (int i = itens.size(); i>-1; i--){
        itens_rev = itens_rev + itens[i];
    }
    std::cout<<itens_rev;
}

void drone(){
    int a, b, c, d;
    std::cin>>a>>b;
    std::cin>>c>>d;
    if ((a == c)&(b == d)){
        printf("Soltar pacote");
    }
    else{
        printf("Nao soltar pacote");
    }
    }

void desenho(){
    std::string linha;
    int p, a, b;
    std::cin>>p;
    a = p - 1;
    b = 1;
    for (int i = 0; i<p; i++){
        linha = "";
        for (int m = 0; m != a; m++){
            linha = linha + ">";  
        }
        for (int z = 0; z != b; z++){
            linha = linha + "#";
        }  
        std::cout<<linha<<std::endl;
        a = a - 1;
        b = b + 1;
    }
}
    
void playlist(){
    int n;
    std::string musica;
    std::cin>>n;
    std::vector<std::string> nomes;
    for (int i = 0; i<n+1; i++){
        getline(std::cin,musica);
        nomes.push_back(musica);
    }
    for (int i = 0; i<(nomes.size()-1); i++){
        for (int m = 0; m<(nomes.size()-1); m++){
            if (nomes[m]>nomes[m+1]){
                std::swap(nomes[m], nomes[m+1]);
            }
        }
    }
    for (int j = 0; j<n + 1; j++){
        std::cout<<nomes[j]<<std::endl;
    }
}

void visto(){
    int p;
    std::cin>>p;
    if ((p%42)==0){printf("Sim");}
    else{printf("Nao");}
}

void media(){
    std::string input;
    std::vector<int> numbers;
    while(true){
        std::cin>>input;

        if (input=="FIM"){
            break;
        }
    
        int number = std::stoi(input);
        numbers.push_back(number);
    }
        if ((numbers.size())==1){
            std::cout<<numbers[0];
        }
        else if((numbers.size())==2){
            int total = numbers[0] + numbers[1];
            std::cout<<(total/2);
        }
        else{
            int max, min, soma;
            soma = 0;
            max = numbers[0];
            min = numbers[0];
            for (int i: numbers){
                if (i>max){max=i;}
                if (min>i){min=i;}
                soma = soma + i;
            }
            soma = (soma-max-min)/(numbers.size()-2);
            std::cout<<soma;
        }
    
}

int main (){
}