#include <iostream>

int fib(){
    int a, b, c, n;
    std::cin>>n;
    a = 0;
    b = 1;
    if (n>3){
      n = n-2;
      for (int i=0;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
      }
    std::cout<<c;
    return 0;
    }
    else {
      switch (n)
      {
      case 0:
        std::cout<<0;
        return 0;
      case 1:
        std::cout<<1;
        break;
      case 2:
        std::cout<<1;
        break;
      case 3:
        std::cout<<2;
        break;
      }
    }
  }

int main(){
  fib();
  return 0;
  }
