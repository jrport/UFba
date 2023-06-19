#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class node{
  public:
  node* next;
  int data;
  node(int num){
    data = num;
    next = nullptr;
  } 
};

class linked_list{
public:
  node* head;
  linked_list(){
    head = nullptr;
  }
  void append(int new_el){
    node* temp; 
    temp = new node(new_el);
    if (head==nullptr){
      head = temp;
    }
    else{
      node* temp1 = head;
      while(temp1!=nullptr){
        temp1=temp1->next;
      }
      temp1->next=temp;
    }
  }
  void check_cycle(){
    node* slow = head;
    node* fast = head;
    bool check = false;
    if (head == nullptr){
      cout<<"Sem Ciclo";
    }
    else{
      while (slow->next=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast){
          cout<<"Ciclo";
          check = true;
        }
        if (!check){
          cout<<"Sem Ciclo";
        }
      }
    }
  }
  node* find(int el){
    node* temp = head;
    while (temp!=nullptr){
      if (temp->data==el){
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
  }
  void link(int a, int b){
    node* primeiro;
    node* segundo;
    primeiro = find(a);
    segundo = find(b);
    if ((primeiro != nullptr)&&(segundo != nullptr)){
      primeiro->next=segundo;
    }
  }
  void display(){
    if (head != nullptr) {
        node* cur = head;
        printf("Lista Encadeada:\n%d ",cur->data);
        while (cur->next!=nullptr){
            cur = cur->next;
            printf("%d ",cur->data);
        };
        std::cout<<"\n";
    }
    else {
        printf("Lista Vazia! \n");
    }
  }
};

int main(){
  string c;
  int a, b, num, size;
  cin>>size;
  cin.ignore();
  getline(cin,c);
  linked_list list;
  istringstream nomes(c);
  while (nomes>>num){
    list.append(num);
  }
  //list.display();
  for (int i=0;i<size;i++){
    cin>>a>>b;
    list.link(a,b);
  }
  list.check_cycle();
  linked_list l;
  l.append(1);
  l.append(2);
  l.display();
}
