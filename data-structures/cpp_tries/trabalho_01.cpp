#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class linked_list {
    public:
    node* head;  
    linked_list(){
        head = nullptr;
    }
    void append(int new_num){
        node* new_val;
        new_val = new node(new_num);
        if (head == nullptr){
            head = new_val;
        }
        else{
            node* cur = head;
            while (cur->next!=nullptr){
                cur = cur->next;
            }
            cur -> next = new_val;
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
    void free(){
        head = nullptr;
    }
    void insert_begin(int new_val){
        node* new_elem = new node(new_val);
        new_elem -> next = head;
        head = new_elem;
    }
    void insert_lista(int indice, int new_val){
        node* cur = head;
        node* new_elem = new node(new_val);
        if (indice>0){
            for (int i = 0; i<indice-1;i++){
                cur = cur->next;
            }
            new_elem->next = cur->next;
            cur -> next = new_elem;
        }
        else{
            insert_begin(new_elem->data);
        }
    }
  bool check_cycle(){
    std::cout<<"LOLO";
    node* slow = head;
    node* fast = head;
    if (head == nullptr){
      std::cout<<"Sem Ciclo";
      return false;
    }
    else{
      while (slow->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast){
          std::cout<<"Ciclo";
          return true;
        }
      }
      return false;
    }
  }
  node* find(int el){
    if (check_cycle()){
      node* temp = head;
      while (temp!=nullptr){
        if (temp->data==el){
          return temp;
        }
        temp = temp->next;
      }
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
};



int main(){
 linked_list list;
  string c;
  int a, b, num, size;
  cin>>size;
  cin.ignore();
  getline(cin,c);
  istringstream nomes(c);
  while (nomes>>num){
    list.append(num);
  }
  list.display();
  for (int i=0;i<size;i++){
    cin>>a>>b;
    list.link(a,b);
  }
  list.check_cycle();
}
