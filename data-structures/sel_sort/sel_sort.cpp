#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

class lnode
{
public:
  int num;
  lnode* pnext;
  lnode(int value){
    num = value;
    pnext = nullptr;
  }
};

class llist
{
public:
  lnode* root;
  llist(){
    root = nullptr;
  }
  void append(int i){
    lnode* new_val = new lnode(i);
    if (root == nullptr){
      root = new_val;
    }
    else{
      lnode* cur = root;
      while (cur -> pnext != nullptr){
        cur = cur -> pnext;
      cur -> pnext = new_val; 
      }
    }
  }
  void print(){
    lnode* cur = root;
    while (cur != nullptr){
      printf("%d ",cur->num);
    }
  } 
};

int main(){
  llist lista;
  lista.append(1);
  lista.append(2);
  lista.append(4);
  lista.append(1);
  lista.print();
}